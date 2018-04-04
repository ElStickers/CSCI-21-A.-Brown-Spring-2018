CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

all: main

#creates the executable from both the object files
main: lab_18_unit_test.o node.o stack.o
	$(CXX) $(CXXFLAGS) -o main lab_18_unit_test.o

#creates the lab2 object file
lab_18_unit_test.o: lab_18_unit_test.cpp node.cpp stack.cpp
	$(CXX) $(CXXFLAGS) -c lab_18_unit_test.cpp node.cpp stack.cpp
	
stack.o: stack.cpp node.cpp
	$(CXX) $(CXXFLAGS) -c stack.cpp node.cpp

# creates the unit test object file
node.o: node.cpp
	$(CXX) $(CXXFLAGS) -c node.cpp
	
unittest: lab_18_unit_test.cpp
	$(CXX) $(CXXFLAGS) -c lab_18_unit_test.cpp

#cleans up old .o files	
clean:
	rm *.o *test 
