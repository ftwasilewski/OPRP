#!/usr/bin/python

fe = open('estatistica.txt', 'r')
fmf = open('medias_float.txt', 'a')
fmi = open('medias_int.txt', 'a')
time = 0.0
col = ''
for line in fe:
	col = line.split(' ')
	time += float(col[1])

fmf.write(str(time/10) + ' ' + col[2])
fmi.write(str(int(time/10)) + ' ' + col[2])

print(time/10)
print(int(time/10))

fe.close()
fmf.close()
fmi.close()	
