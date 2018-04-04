CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

all: main

#creates the executable from both the object files
main: test.o node.o 
	$(CXX) $(CXXFLAGS) -o main test.o

#creates the lab2 object file
test.o: test.cpp node.cpp  
	$(CXX) $(CXXFLAGS) -c test.cpp node.cpp

# creates the unit test object file
node.o: node.cpp
	$(CXX) $(CXXFLAGS) -c node.cpp
	
unittest: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp

#cleans up old .o files	
clean:
	rm *.o *test 
