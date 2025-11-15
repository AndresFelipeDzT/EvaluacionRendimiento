# EvaluacionRendimiento
# Antes de iniciar
Resumen de la estructura de carpetas y que encontrar en cada una de ellas.
# Documentos

En esta carpeta se encuentran:

Taller Evaluación Rendimiento.pdf: documento con el análisis, diseño, resultados y conclusiones.

Tablas.xlsx: archivo con los datos resultantes de las ejecuciones, en tablas organizadas con tamaño de la matriz (NxN), número de hilos y tiempos promedio (de las 30 ejecuciones).

# Codigo

Contiene todos los programas, comentados y con su respectivo fichero

Archivo	Descripción


Makefile	Compila todas las implementaciones.


mmClasicaFork.c	Implementación basada en procesos Fork.


mmClasicaPosix.c	Implementación utilizando hilos Posix.


mmClasicaOpenMP.c	Multiplicación de matrices utilizando OpenMP.


mmFilasOpenMP.c	Implementación OpenMP con matriz transpuesta.


Funciones.c y Funciones.h	Librería con las funciones comunes utilizadas por los programas.


lanzador.pl	Script que automatiza la ejecución repetitiva de pruebas.


# DatosDeResultados

En esta se encuentran dos carpetas CSV y DAT. Ambas contienen los mismos archivos con los datos obtenidos al ejecutar el lanzador indicando nombre del programa, tamaño de la matriz y numero de hilos en su nombre más extensión, se opto por poner dos carpetas la de los .dat al ser las que se generaban originalmente + la de csv que era la solicitada en el enunciado pero ambas tienen los mismos archivos con diferente extensión.

DAT: archivos generados directamente por el script de ejecución.

CSV: mismos archivos convertidos al formato solicitado para facilitar análisis estadístico o visualización.
