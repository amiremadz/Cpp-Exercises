GCC_OPT=-Wall -std=c++11

all: main.o MA.o
	g++ main.o MA.o -o runme.out $(GCC_OPT)

main.o: main.cpp
	g++ -c main.cpp $(GCC_OPT)

MA.o: MA.cpp
	g++ -c MA.cpp $(GCC_OPT)

clean:
	rm -f *.o
