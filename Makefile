main.out: main.o
	clang -Wall -o main.out main.o

main.o: main.c trig_table.h
	clang -c -o main.o main.c

clean:
	rm main.o main.out output.txt

all: clean main.o main.out
