all: linked

linked: l_lists.o main.o
	gcc -o linked main.c l_list/l_lists.c

l_lists.o:	l_list/l_lists.c
	gcc -c l_list/l_lists.c

main.o:	main.c
	gcc -c main.c

clean: 
	rm -rf *.o linked