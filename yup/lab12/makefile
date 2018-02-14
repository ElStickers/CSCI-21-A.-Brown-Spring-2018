CXX = g++
CXXFLAGS = -Wall -g

main.exe: item.o food_item.o magic_item.o lab_12_unit_test.o
	$(CXX) $(CXXFLAGS) -o main.exe item.o food_item.o magic_item.o lab_12_unit_test.o
	
item.o: item.cpp item.h
	$(CXX) $(CXXFLAGS) -c item.cpp
	
magic_item.o: magic_item.cpp magic_item.h
	$(CXX) $(CXXFLAGS) -c magic_item.cpp

food_item.o: food_item.cpp food_item.h
	$(CXX) $(CXXFLAGS) -c food_item.cpp
	
lab_12_unit_test.o: lab_12_unit_test.cpp
	$(CXX) $(CXXFLAGS) -c lab_12_unit_test.cpp