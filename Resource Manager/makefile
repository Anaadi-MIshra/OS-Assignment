make: main.o functions.o
	gcc -o Resource\ Manager main.o functions.o -pthread

main.o: main.c
	gcc -o main.o -c main.c

functions.o: functions.c
	gcc -o functions.o -c functions.c