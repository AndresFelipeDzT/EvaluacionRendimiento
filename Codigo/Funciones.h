/******************************************************
* Fecha 6/11/2025
* Pontificia Universidad Javeriana
* Profesor: J. Corredor, PhD
* Autor: Andres Diaz
* Materia: Sistemas opertivos
* Programa: prototipos de las funciones
* Version:
*    Funciones de multiplicacion de matrcies para
*    todos los metodos
******************************************************/
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h> //Libreria que sirve para mostrar datos por pantalla
#include <stdlib.h> //Libreria relacionada con memoria dinamica
#include <sys/time.h> //Libreria de tiempo

// Variables globales
extern struct timeval inicio, fin;

// Prototipos 
void InicioMuestra(); //Funcion para empezar a contar el tiempo
void FinMuestra(); //Funcion para parar de contar e tiempo
void iniMatrix(double *m1, double *m2, int D, double min1, double max1, double min2, double max2); //Funcion para inicializar las dos matrices que se van a multiplicar
void impMatrix(double *matriz, int D, int tipo); //Funcion para mostrar las matrices

#endif
