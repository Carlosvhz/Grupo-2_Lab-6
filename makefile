run.o:	main.o persona.o
	g++ main.o persona.o -o run

main.o:	persona.h main.cpp
	g++ -c main.cpp

persona.o:	persona.h persona.cpp
	g++ -c persona.cpp

clear:
	rm *.o run
