make: main.o add.o mul.o sub.o
	gcc -o Arith main.o add.o sub.o mul.o

main.o: main.c
	gcc -o main.o -c main.c

add.o: add.c
	gcc -o add.o -c add.c

sub.o: sub.c
	gcc -o sub.o -c sub.c

mul.o: mul.c
	gcc -o mul.o -c mul.c		

clean:
	rm -rf *.o 	

library: add.o sub.o mul.o
		gcc -o libarith.so add.o sub.o mul.o -shared -fPIC	

final: main.o  
	export LD_LIBRARY_PATH=.
	gcc -o FINAL main.o libarith.so		