GCC_OPT=-Wall -std=c++11

all: main.o Logger.o
	g++ main.o Logger.o -o runme.out $(GCC_OPT)

main.o: main.cpp
	g++ main.cpp -c $(GCC_OPT)

Logger.o: Logger.cpp
	g++ Logger.cpp -c $(GCC_OPT)

clean:
	rm -f *.o
