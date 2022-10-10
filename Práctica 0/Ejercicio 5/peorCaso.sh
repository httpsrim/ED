#!/bin/bash

g++ -g peor_caso.cpp -o peor
inicio=100
fin=30000
incremento=500
ejecutable="peor"
salida="tiempos_ordenacion_peor_caso.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
	echo "Ejecución tam = " $i
	echo `./$ejecutable $i` >> $salida
	i=$[ $i + $incremento ]
done 
