FLAGS = -Wall -Wextra -ansi -pedantic -g

prog: main.o arbre.o pile.o
	gcc -o prog main.o arbre.o pile.o ${FLAGS}

main.o: main.c 
	gcc -o main.o -c main.c ${FLAGS}

arbre.o: arbre.c 
	gcc -o arbre.o -c arbre.c ${FLAGS}

pile.o: pile.c
	gcc -o pile.o -c pile.c ${FLAGS}
