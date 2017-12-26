GCC_OPT=-Wall -std=c++11

all:before.o after.o
	g++ before.o -o before.out $(GCC_OPT)
	g++ after.o -o after.out $(GCC_OPT)

before.o: before.cpp
	g++ -c before.cpp $(GCC_OPT)

after.o: after.cpp
	g++ -c after.cpp $(GCC_OPT)

clean:
	rm -f *.o

