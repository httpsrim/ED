#!/bin/bash

g++ -O3 ordenacion.cpp -o ordenacion_optimizado
inicio=100
fin=30000
incremento=500
ejecutable="ordenacion_optimizado"
salida="tiempos_mejorados.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
	echo "Ejecución tam = " $i
	echo `./$ejecutable $i` >> $salida
	i=$[ $i + $incremento ]
done 
