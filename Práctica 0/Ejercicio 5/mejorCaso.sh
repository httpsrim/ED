#!/bin/bash

g++ -g mejor_caso.cpp -o mejor
inicio=100
fin=30000
incremento=500
ejecutable="mejor"
salida="tiempos_ordenacion_mejor_caso.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
	echo "Ejecución tam = " $i
	echo `./$ejecutable $i` >> $salida
	i=$[ $i + $incremento ]
done 
