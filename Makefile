all:main2 

main2: main.o libcal.so
	gcc main.c libcal.so -o main
main.o: main.c
	gcc -c main.c -fPIC

cal.o: cal.c
	gcc -c cal.c -fPIC

check.o: check.c
	gcc -c check.c -fPIC

libcal.so: cal.o check.o
	gcc -shared -o libcal.so cal.o check.o 



