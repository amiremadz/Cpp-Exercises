GCC_OPTS=-Wall -std=c++11

all: main.o Bits.o
	g++ main.o Bits.o -o runme.out $(GCC_OPTS)

main.o: main.cpp
	g++ -c main.cpp $(GCC_OPTS)

Bits.o: Bits.cpp
	g++ -c Bits.cpp $(GCC_OPTS)

clean:
	rm -f *.o

#g++ main.cpp Bits.hpp Bits.cpp -o runme.out -std=c++11
