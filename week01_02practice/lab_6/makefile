CXX = g++
CXXFLAGS = -Wall -g

main: lab_6_unit_test.o lab_6.o
	$(CXX) $(CXXFLAGS) -o main lab_6_unit_test.o lab_6.o
	
lab_6_unit_test.o: lab_6_unit_test.cpp
	$(CXX) $(CXXFLAGS) -c lab_6_unit_test.cpp
	
lab_6.o: lab_6.cpp
	$(CXX) $(CXXFLAGS) -c lab_6.cpp
