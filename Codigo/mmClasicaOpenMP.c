/******************************************************
* Fecha 6/11/2025
* Pontificia Universidad Javeriana
* Profesor: J. Corredor, PhD
* Autor: Andres Diaz
* Materia: Sistemas opertivos
* programa: Multiplicacion de Matrices algoritmo clasico
* version:
*    Paralelismo con OpenMP
******************************************************/

#include <omp.h> //Libreria para OpenMP
#include <time.h> //Libreria para aleatorio
#include "Funciones.h" //Donde estan las otras funciones

void multiMatrix(double *mA, double *mB, double *mC, int D) {
    double Suma, *pA, *pB;
    #pragma omp parallel
    {
        #pragma omp for //Divide las operaciones para los hilos
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < D; j++) { //Doble for para recorrer la matriz
                pA = mA + i * D; //Lo que hay en la fila
                pB = mB + j; //Lo que hay en la columna
                Suma = 0.0; //inicializador para la suma en 0
                for (int k = 0; k < D; k++, pA++, pB += D) {
                    Suma += *pA * *pB; //Producto escalar de las filas y columnas
                }
                mC[i * D + j] = Suma; //Se almacena lo de la multiplicacion
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) { //Revisa que le pasaron los argumentos que son, tamano e hilos
        printf("\n Use: $./MM_OpenMP SIZE Hilos \n\n");
        exit(0);
    }

    int N = atoi(argv[1]); //Tamano matriz
    int TH = atoi(argv[2]); //Numero de hilos
    //Guarda el espacio en la memoria para las dos matrices a multiplicar y la de resultado
    double *matrixA = (double *)calloc(N * N, sizeof(double));
    double *matrixB = (double *)calloc(N * N, sizeof(double));
    double *matrixC = (double *)calloc(N * N, sizeof(double));

    srand(time(NULL));
    omp_set_num_threads(TH); //Numero de hilos a usar

    iniMatrix(matrixA, matrixB, N, 1.0, 5.0, 2.0, 9.0);
    impMatrix(matrixA, N, 0);  //Muestra la matriz A
    impMatrix(matrixB, N, 0);  //Muestra la matriz B

    InicioMuestra(); //Inicia el tiempo
    multiMatrix(matrixA, matrixB, matrixC, N); //Multiplica
    FinMuestra(); //Termina el contador

    impMatrix(matrixC, N, 0); //Muestra la matriz resultado
    //Libera el espacio reservado para las 3 matrices
    free(matrixA);
    free(matrixB);
    free(matrixC);

    return 0;
}
