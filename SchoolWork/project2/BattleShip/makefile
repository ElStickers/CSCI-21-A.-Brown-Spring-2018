CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

all: main

main: tests.o board.o
	$(CXX) $(CXXFLAGS) -o main tests.o
	
tests.o: tests.cpp board.cpp
	$(CXX) $(CXXFLAGS) -c tests.cpp board.cpp
	
board.o: board.cpp
	$(CXX) $(CXXFLAGS) -c board.cpp

clean:
	rm -rf *.o