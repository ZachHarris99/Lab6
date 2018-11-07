#	Author: John Gibbons
#	Date: 2016.10.26


#Add needed Test.o
prog: main.o
	g++ -g -Wall -std=c++11 main.o LinkedListOfInts.o -o prog


main.o: main.cpp catch.hpp
	g++ -g -Wall -std=c++11 -c main.cpp


#DON'T delete LinkedList.o!
clean:
	rm main.o *.*~ prog
