#!/usr/bin/gnuplot
reset
set terminal png size 640,480
set xlabel "Quantidade de threads"
set ylabel "Eficiência"
set grid
set style data linespoints
set output "eficiencia.png"
plot "dados_openmp.dat" using ($4):($3) title "OpemMP", \
     "dados_pthread.dat" using ($4):($3) title "Pthread"
