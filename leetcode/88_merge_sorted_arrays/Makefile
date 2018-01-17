GCC_OPT=-Wall -std=c++11

all: main.o
	g++ main.o -o runme.out $(GCC_OPT)

main.o: main.cpp
	g++ -c main.cpp $(GCC_OPT)

clean:
	rm -f *.o

