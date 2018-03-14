CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

all: main

main: unit_test.o challenge4.o
	$(CXX) $(CXXFLAGS) -o main unit_test.o challenge4.o

unit_test.o: unit_test.cpp challenge4.cpp
	$(CXX) $(CXXFLAGS) -c unit_test.cpp challenge4.cpp

challenge4.o: challenge4.cpp
	$(CXX) $(CXXFLAGS) -c challenge4.cpp

clean:
	rm -rf *.o