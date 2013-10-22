#!/usr/bin/python

fe = open('estatistica.txt', 'r')
fs = open('media_serial.dat', 'r')
fmf = open('dados_openmp.dat', 'a')
#fmi = open('medias_int.txt', 'a')

time = 0.0
col = ''
cont = 0

for line in fs:
	media_serial = float(line.split(' ')[0])

for line in fe:
	cont = cont + 1
	col = line.split(' ')
	time += float(col[1])
	if cont == 10 :
		fmf.write(str(time/10) + ' ' + str(media_serial/(time/10)) + ' ' + str((media_serial/(time/10))/(float(col[2]))) + ' ' + col[2])
		#fmi.write(str(int(time/10)) + ' ' + col[2])
		time = 0.0
		cont = 0

fe.close()
fmf.close()
#fmi.close()

