# ******************************************************
# Fecha: 11/11/2025
# Pontificia Universidad Javeriana
# Profesor: J. Corredor, PhD
# Autor: Andres Diaz
# Materia: Sistemas Operativos
# Temas: Makefile
# ******************************************************
#Indica que se compila con gcc
CC = /opt/local/bin/gcc-mp-13
#Flags para optimizar y el lanzador
CFLAGS = -O3 -lm
#Para que soporte OpenMP
FOPENMP = -fopenmp
#Para el manejo de hilos
POSIX = -lpthread
#Que se quiere compilar los 4 archivos de multiplicacion de matrices
PROGRAMAS = MM_Fork MM_Posix MM_OpenMP MM_FilasOpenMP
#Que compile todos los objetivos
All: $(PROGRAMAS)
#Adicional a clasica fork que considere el archivo de funciones
MM_Fork: mmClasicaFork.c Funciones.c
	$(CC) $(CFLAGS) $^ -o $@
#Adicional a clasica posix que considere el archivo de funciones
MM_Posix: mmClasicaPosix.c Funciones.c
	$(CC) $(CFLAGS) $^ -o $@ $(POSIX)
#Adicional a clasica openMp que considere el archivo de funciones
MM_OpenMP: mmClasicaOpenMP.c Funciones.c
	$(CC) $(CFLAGS) $^ -o $@ $(FOPENMP)
#Adicional a filas openMp que considere el archivo de funciones
MM_FilasOpenMP: mmFilasOpenMP.c Funciones.c
	$(CC) $(CFLAGS) $^ -o $@ $(FOPENMP)
#Elimina los ejecutables
clean:
	rm -f $(PROGRAMAS)


