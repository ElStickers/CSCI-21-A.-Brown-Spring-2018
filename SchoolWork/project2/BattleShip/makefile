CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

all: main

main: tests.o board.o player.o human.o
	$(CXX) $(CXXFLAGS) -o main tests.o
	
tests.o: tests.cpp board.cpp player.cpp human.cpp
	$(CXX) $(CXXFLAGS) -c tests.cpp board.cpp player.cpp human.cpp
	
board.o: board.cpp
	$(CXX) $(CXXFLAGS) -c board.cpp
	
player.o: player.cpp board.cpp
	$(CXX) $(CXXFLAGS) -c player.cpp board.cpp

human.o: human.o player.o board.o
	$(CXX) $(CXXFLAGS) -c human.cpp player.cpp board.cpp

clean:
	rm -rf *.o