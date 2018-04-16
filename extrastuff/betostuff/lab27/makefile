CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

#name of the executable file
all: main

main: lab27.o activity.o
	$(CXX) $(CXXFLAGS) -o main lab27.o activity.o
	
lab27.o: lab27.cpp activity.cpp
	$(CXX) $(CXXFLAGS) -c lab27.cpp activity.cpp

activity.o: activity.cpp
	$(CXX) $(CXXFLAGS) -c activity.cpp
	
clean:
	rm -rf *.o