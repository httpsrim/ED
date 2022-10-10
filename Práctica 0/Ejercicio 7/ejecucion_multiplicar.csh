#!/bin/csh 

@ inicio = 4
@ fin = 50000

alias MATH 'set \!:1 = `echo "\!:3-$" | bc -l`' 
set ejecutable = multiplicar
set salida = tiempos_multiplicar.dat
@ factor = 2
@ i = $inicio

echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
   
   if ($i >= 65536) then
    @ factor = 2
   endif 
   MATH  nuevo = $i*$factor
   
   @ i = $nuevo 
   
end
