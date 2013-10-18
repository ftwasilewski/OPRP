# GNU Makefile

CC = gcc
LDFLAGS = -lm
TARGET = fractal 

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@ 

all: $(TARGET)

# Dependencias

fractal: matrix.o fractal.c
matrix.o: matrix.c matrix.h

clean:
	rm -f *.o *~ $(TARGET)
