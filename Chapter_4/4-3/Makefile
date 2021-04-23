objects = main.o getch.o getop.o stack.o
calc : $(objects)
	gcc -g $(objects) -o calc 

$(objects) : calc.h 

clean : 
	rm calc $(objects)
