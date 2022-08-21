all: c
c: cellular.c cellular.h menu.c
	gcc -o c menu.c cellular.c
