#!/usr/bin/gnuplot
reset
set terminal png size 640,480
set xlabel "Quantidade de threads"
set ylabel "Aceleração"
set yrange [0:8]
set key left
set grid
set style data linespoints
set output "aceleracao.png"
plot "aceleracao_ideal.dat" using ($2):($1) title "Ideal", \
     "dados_openmp.dat" using ($3):($2) title "OpenMP", \
     "dados_pthread.dat" using ($3):($2) title "Pthread"
