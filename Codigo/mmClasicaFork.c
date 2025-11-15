/******************************************************
* Fecha 6/11/2025
* Pontificia Universidad Javeriana
* Profesor: J. Corredor, PhD
* Autor: Andres Diaz
* Materia: Sistemas opertivos
* Programa: Multiplicacion de Matrices algoritmo clasico
* Version:
*    Paralelismo con Procesos Fork
******************************************************/

#include <unistd.h> //Libreria para poder usar fork
#include <sys/wait.h> //Libreria para indicarle a los hijos que esperen mini sincronizacion
#include <time.h> //Libreria para aleatorio
#include "Funciones.h" //Donde estan las otras funciones
//Funcion para multiplicar matrices
void multiMatrix(double *mA, double *mB, double *mC, int D, int filaI, int filaF) {
    double Suma, *pA, *pB; //Variables
    for (int i = filaI; i < filaF; i++) { //Doble for para recorrer la matriz
        for (int j = 0; j < D; j++) {
            Suma = 0.0; //inicializador para la suma en 0
            pA = mA + i * D; //Lo que hay en la fila
            pB = mB + j; //Lo que hay en la columna
            for (int k = 0; k < D; k++, pA++, pB += D) {
                Suma += *pA * *pB; //Producto escalar de las filas y columnas
            }
            mC[i * D + j] = Suma; //Se almacena lo de la multiplicacion
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) { //Revisa que le pasaron los argumentos que son, tamano e hilos
        printf("\n Use: $./MM_ClasicaFork Size Procesos\n");
        exit(0);
    }

    int N = atoi(argv[1]); //Tamano matriz
    int num_P = atoi(argv[2]); //Numero de hilos
    //Guarda el espacio en la memoria para las dos matrices a multiplicar y la de resultado
    double *matA = (double *)calloc(N * N, sizeof(double));
    double *matB = (double *)calloc(N * N, sizeof(double));
    double *matC = (double *)calloc(N * N, sizeof(double));

    srand(time(0));
    iniMatrix(matA, matB, N, 1.0, 5.0, 5.0, 9.0);
    impMatrix(matA, N, 0);
    impMatrix(matB, N, 0);

    int rows_per_process = N / num_P;
    InicioMuestra(); //Inicia el tiempo

    for (int i = 0; i < num_P; i++) {
        pid_t pid = fork(); //Crea el proceso hijo
        if (pid == 0) {
            int start_row = i * rows_per_process; //Cuantas filas le tocaron
            int end_row = (i == num_P - 1) ? N : start_row + rows_per_process;
            multiMatrix(matA, matB, matC, N, start_row, end_row); //Multiplica
            exit(0);
        } else if (pid < 0) { //lanza error ya que no logro crear al hijo
            perror("fork failed");
            exit(1);
        }
    }

    for (int i = 0; i < num_P; i++) wait(NULL);

    FinMuestra(); //Termina el contador
    impMatrix(matC, N, 0); //Muestra la matriz
    //Libera el espacio reservado para las 3 matrices
    free(matA);
    free(matB);
    free(matC);
    return 0;
}
