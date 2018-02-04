/*
 * Programming Challenge 12
 *
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <streambuf>
#include <string>
#include <vector>
using namespace std;

// class Collector goes here

string checkStringOutput (Collector& coll);

/*
 * CATCH unit tests
 */
TEST_CASE ("ShoppingList class functionality", "[ShoppingList]") {
 	Collector collectorOne;
 	Collector collectorTwo("Lara Croft");

 	CHECK(collectorOne.getName() == "No Name");
 	CHECK(collectorOne.getCollectionSize() == 0);
 	collectorOne.setName("Indiana Jones");
 	CHECK(collectorOne.getName() == "Indiana Jones");
 	CHECK(collectorTwo.removeItem(-1) == false);
 	CHECK(collectorOne.removeItem(0) == false);

 	streambuf* oldCout = cout.rdbuf();
	ostringstream captureCout;
	cout.rdbuf(captureCout.rdbuf());
	collectorOne.describe();
	CHECK(captureCout.str() == checkStringOutput(collectorOne));
	cout.rdbuf(oldCout);
	captureCout.str("");
	captureCout.clear();

	CHECK(collectorTwo.getName() == "Lara Croft");

	collectorTwo.addItem("stone dragon");
	collectorTwo.addItem("compass");
	collectorTwo.addItem("jade dragon");
	collectorTwo.addItem("map");
	collectorTwo.addItem("gold dragon");

	oldCout = cout.rdbuf();
	cout.rdbuf(captureCout.rdbuf());
	collectorTwo.describe();
	CHECK(captureCout.str() == checkStringOutput(collectorTwo));
	cout.rdbuf(oldCout);
	captureCout.str("");
	captureCout.clear();

	CHECK(collectorTwo.getCollectionSize() == 5);
	CHECK(collectorTwo.getItem(0) == "stone dragon");
	CHECK(collectorTwo.getItem(2) == "jade dragon");
	CHECK(collectorTwo.getItem(4) == "gold dragon");

	CHECK(collectorTwo.removeItem(0) == true);
	CHECK(collectorTwo.getItem(0) == "compass");
	CHECK(collectorTwo.getCollectionSize() == 4);

	CHECK(collectorTwo.removeItem(3) == true);
	CHECK(collectorTwo.getItem(2) == "map");
	CHECK(collectorTwo.getCollectionSize() == 3);

	CHECK(collectorTwo.removeItem(1) == true);
	CHECK(collectorTwo.getCollectionSize() == 2);

	CHECK(collectorTwo.removeItem(0) == true);
	CHECK(collectorTwo.getCollectionSize() == 1);

	CHECK(collectorTwo.removeItem(0) == true);
	CHECK(collectorTwo.getCollectionSize() == 0);

	CHECK(collectorTwo.removeItem(0) == false);

	oldCout = cout.rdbuf();
	cout.rdbuf(captureCout.rdbuf());
	collectorTwo.describe();
	CHECK(captureCout.str() == checkStringOutput(collectorTwo));
	cout.rdbuf(oldCout);
	captureCout.str("");
	captureCout.clear();
}

string checkStringOutput (Collector& coll) {
	stringstream ss;
	
	ss << coll.getName() << "'s collection:\n\n";

	if (coll.getCollectionSize() == 0) {
		ss << "EMPTY" << endl;
	} else {
		for (int i=0; i<coll.getCollectionSize(); i++) {
			ss << coll.getItem(i) << endl;
		}
	}

	return ss.str();
}