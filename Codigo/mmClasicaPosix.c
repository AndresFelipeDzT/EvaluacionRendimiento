/******************************************************
* Fecha 6/11/2025
* Pontificia Universidad Javeriana
* Profesor: J. Corredor, PhD
* Autor: Andres Diaz
* Materia: Sistemas opertivos
* Programa: Multiplicacion de Matrices algoritmo clasico
* Version:
*    Paralelismo con Hilos Pthreads "Posix"
******************************************************/

#include <pthread.h> //Libreria para hilos y posix
#include <unistd.h>
#include <time.h> //Libreria para aleatorio
#include "Funciones.h" //Donde estan las otras funciones

pthread_mutex_t MM_mutex; //Mutex para sincronizar
double *matrixA, *matrixB, *matrixC; //Las matrices

struct parametros {
    int nH; //Numero de hijos
    int idH; //ID del hijo
    int N; //Tamano de la matriz
};
//Lo que ejecuta cada uno de los hilos
void *multiMatrix(void *variables) {
    struct parametros *data = (struct parametros *)variables;
    //Obtener los datos de la estructura de antes
    int idH = data->idH;
    int nH = data->nH;
    int D = data->N;
    int filaI = (D / nH) * idH;
    int filaF = (D / nH) * (idH + 1);
    double Suma, *pA, *pB; //Variables para multiplicar

    for (int i = filaI; i < filaF; i++) {
        for (int j = 0; j < D; j++) {
            pA = matrixA + i * D; //Lo que hay en la fila
            pB = matrixB + j; //Lo que hay en la columna
            Suma = 0.0; //inicializador para la suma en 0
            for (int k = 0; k < D; k++, pA++, pB += D) {
                Suma += *pA * *pB; //Producto escalar de las filas y columnas
            }
            matrixC[i * D + j] = Suma; //Se almacena lo de la multiplicacion
        }
    }

    pthread_mutex_lock(&MM_mutex);
    pthread_mutex_unlock(&MM_mutex);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 3) { //Revisa que le pasaron los argumentos que son, tamano e hilos
        printf("Uso: $./MM_Posix tamMatriz numHilos\n");
        exit(0);
    }

    int N = atoi(argv[1]); //Tamano matriz
    int n_threads = atoi(argv[2]); //Numero de hilos
    pthread_t p[n_threads];
    pthread_attr_t atrMM;
   //Guarda el espacio en la memoria para las dos matrices a multiplicar y la de resultado
    matrixA = (double *)calloc(N * N, sizeof(double));
    matrixB = (double *)calloc(N * N, sizeof(double));
    matrixC = (double *)calloc(N * N, sizeof(double));

    srand(time(NULL));
    iniMatrix(matrixA, matrixB, N, 1.0, 5.0, 5.0, 9.0);
    impMatrix(matrixA, N, 0);
    impMatrix(matrixB, N, 0);

    InicioMuestra(); //Inicia el tiempo

    pthread_mutex_init(&MM_mutex, NULL); //Iniciliza el mutex
    pthread_attr_init(&atrMM);
    pthread_attr_setdetachstate(&atrMM, PTHREAD_CREATE_JOINABLE); //Que se pueda hacer join

    for (int j = 0; j < n_threads; j++) {
        //Reserva la memoria
        struct parametros *datos = (struct parametros *)malloc(sizeof(struct parametros));
        //Asigna los valores
        datos->idH = j;
        datos->nH = n_threads;
        datos->N = N;
        //Crea el hilo
        pthread_create(&p[j], &atrMM, multiMatrix, (void *)datos);
    }

    for (int j = 0; j < n_threads; j++) pthread_join(p[j], NULL);

    FinMuestra(); //Termina el contador
    impMatrix(matrixC, N, 0); //Muestra la matriz
    //Libera el espacio reservado para las 3 matrices
    free(matrixA);
    free(matrixB);
    free(matrixC);

    pthread_attr_destroy(&atrMM);
    pthread_mutex_destroy(&MM_mutex); //Libera el mutex
    pthread_exit(NULL);

    return 0;
}
