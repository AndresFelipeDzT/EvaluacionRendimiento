/******************************************************
* Fecha 6/11/2025
* Pontificia Universidad Javeriana
* Profesor: J. Corredor, PhD
* Autor: Andres Diaz
* Materia: Sistemas opertivos
* Programa:  Implementacion de las funciones
* Version:
*    Funciones de multiplicacion de matrcies para
*    todos los metodos
******************************************************/
#include "Funciones.h"

struct timeval inicio, fin; //Variables globales para guardar el momento de inicio, de fin y el total

void InicioMuestra() { //Toma la hora actual y la guarda en inicio
    gettimeofday(&inicio, (void *)0);
}

void FinMuestra() {
    gettimeofday(&fin, (void *)0); //toma la hora actual y la guarda en fin
    fin.tv_usec -= inicio.tv_usec;
    fin.tv_sec  -= inicio.tv_sec; //Calcula el tiempo entre inicio y fin
    double tiempo = (double)(fin.tv_sec * 1000000 + fin.tv_usec); //Guarda el tiempo total
    printf("%9.0f \n", tiempo); //Lo muestra en pantalla
}

void iniMatrix(double *m1, double *m2, int D, double min1, double max1, double min2, double max2) {
    for (int i = 0; i < D * D; i++, m1++, m2++) {
        *m1 = (double)rand() / RAND_MAX * (max1 - min1) + min1; //LLena la matriz uno con valores aleatorios
        *m2 = (double)rand() / RAND_MAX * (max2 - min2) + min2; //LLena la matriz dos con valores aleatorios
    }
}

void impMatrix(double *matriz, int D, int tipo) {
    if (D < 9) { //Restringe el tamano a maximo 8
        printf("\n");
        if (tipo == 0) { // normal
            for (int i = 0; i < D * D; i++) { //La recorre e imprime
                if (i % D == 0) printf("\n"); //Dependiendo del tamano hace salto de linea
                printf(" %.2f ", matriz[i]);
            }
        } else { // transpuesta
            for (int j = 0; j < D; j++) { //Intercambia filas y columnas
                for (int i = 0; i < D; i++) //Recorre e imprime
                    printf(" %.2f ", matriz[i * D + j]);
                printf("\n"); //Saltos de linea para que quede como matriz
            }
        }
        printf("\n--------------------\n");
    }
}
