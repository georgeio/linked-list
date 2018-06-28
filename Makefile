all: linked

linked: l_funcs.o main.o
	gcc -o linked -g l_funcs.c main.c

l_funcs.o:	l_funcs.c
	gcc -c l_funcs.c

main.o:	main.c
	gcc -c main.c

clean: 
	rm -rf *.o linked