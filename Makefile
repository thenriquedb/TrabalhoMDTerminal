main:	main.o	graph.o testes.o saida.o
		gcc	 main.o	graph.o	testes.o saida.o -o pdif-solver
		rm *.o

main.o:
		gcc -c main.c

graph.o:
		gcc -c	graph.c

testes.o:
	gcc -c testes.c

saida.o:
	gcc -c saida.c
