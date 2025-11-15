#!/usr/bin/perl
#**************************************************************
#         		Pontificia Universidad Javeriana
#     Autor: Andres Diaz
#     Fecha: 14/11/2025
#     Materia: Sistemas Operativos
#     Tema: Taller de Evaluación de Rendimiento
#     Fichero: script automatización ejecución por lotes 
#****************************************************************/

use strict;
use warnings;

my $Path = `pwd`;
chomp($Path);

#nombre del archivo compilado
my $Nombre_Ejecutable = "MM_Fork";

#Tamano matriz
my @Size_Matriz = ("20");
#Hilos con los que se va aprobar
my @Num_Hilos = (1, 2, 4, 8, 16, 20);
#Cuantas repeticiones
my $Repeticiones = 30;
#Para cada tamano de matriz
foreach my $size (@Size_Matriz) {
	#Para cada cantidad de hilos
	foreach my $hilo (@Num_Hilos) {
		#En el archivo con el nombre del ejecutable y numero de hilos
		my $file = "$Path/$Nombre_Ejecutable-$size-Hilos-$hilo.dat";
		print "\n Ejecutando $Nombre_Ejecutable tamaño=$size hilos=$hilo ($Repeticiones repeticiones)\n";
		#Ejecuta el programa y guarda los resultados
		for (my $i = 0; $i < $Repeticiones; $i++) {
			system("\"$Path/$Nombre_Ejecutable\" $size $hilo >> \"$file\"");
		}
	}
}




