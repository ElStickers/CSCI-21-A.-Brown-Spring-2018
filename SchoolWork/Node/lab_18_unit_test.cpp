/*
 * Name        : lab_18_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #18 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// For NULL
#include <cstddef>
#include <sstream>
using std::stringstream;

#include "stack.cpp"
#include "node.cpp"
// To test for Header guards
#include "stack.h"
//#include "node.cpp"

TEST_CASE("Default Constructor for Node") {
  Node node, node2;
  Node* p_node2 = &node2;
  SECTION("Accessor for Contents") {
    CHECK(node.contents() == "");
  }

  SECTION("Accessor for Next Node") {
    CHECK(node.next_node() == NULL);
  }

  SECTION("Mutator for Contents") {
    node.set_contents("Sarah");
    CHECK(node.contents() == "Sarah");
  }

  SECTION("Mutator for Next Node") {
    node.set_next_node(&node2);
    CHECK(node.next_node() == p_node2);
  }
}

TEST_CASE("Overloaded Constructor for Node") {
  Node node("Jackson"), node2;
  Node* p_node2 = &node2;
  SECTION("Accessor for Contents") {
    CHECK(node.contents() == "Jackson");
  }

  SECTION("Accessor for Next Node") {
    CHECK(node.next_node() == NULL);
  }

  SECTION("Mutator for Contents") {
    node.set_contents("OhMyGod");
    CHECK(node.contents() == "OhMyGod");
  }

  SECTION("Mutator for Next Node") {
    node.set_next_node(&node2);
    CHECK(node.next_node() == p_node2);
  }
}

TEST_CASE("Testing Pointers for Node") {
  Node* node = new Node("Steve");
  Node* node2 = new Node();
  node->set_next_node(node2);
  node2->set_next_node(node);
  // node and node2 now connect each to the other -- not something you should
  // ever do outside of a testing situation
  SECTION("Node 1 Points to Node 2") {
    CHECK(node->next_node() == node2);
  }

  SECTION("Node 2 Points to Node 1") {
    CHECK(node2->next_node() == node);
  }

  SECTION("Node 1 Points to NULL") {
    node->set_next_node(NULL);
    CHECK(node->next_node() == NULL);
  }

  SECTION("Node 2 Points to NULL") {
    node2->set_next_node(NULL);
    CHECK(node2->next_node() == NULL);
  }
}


TEST_CASE("Default Constructor for Stack") {
  Stack stack;
  SECTION("Accessor for Size") {
    CHECK(stack.size() == 0);
  }

  SECTION("ToString()") {
    CHECK(stack.ToString() == "");
  }

  SECTION("RemoveHead() on an Empty List") {
    stack.RemoveHead();
    CHECK(stack.size() == 0);
    CHECK(stack.ToString() == "");
  }
}

TEST_CASE("Building your Linked List") {
  Stack stack;
  stack.InsertHead("1");
  SECTION("InsertHead(1)") {
    CHECK(stack.size() == 1);
    CHECK(stack.ToString() == "1");
  }

  stack.RemoveHead();
  SECTION("RemoveHead()") {
    CHECK(stack.size() == 0);
    CHECK(stack.ToString() == "");
  }

  stack.InsertHead("10"), stack.InsertHead("20");
  SECTION("InsertHead(10), InsertHead(20)") {
    CHECK(stack.size() == 2);
    CHECK(stack.ToString() == "20, 10");
  }

  stack.RemoveHead();
  SECTION("RemoveHead()") {
    CHECK(stack.size() == 1);
    CHECK(stack.ToString() == "10");
  }

  stack.InsertHead("5");
  SECTION("InsertHead(5)") {
    CHECK(stack.size() == 2);
    CHECK(stack.ToString() == "5, 10");
  }

  stack.Clear();
  SECTION("Clear()") {
    CHECK(stack.size() == 0);
    CHECK(stack.ToString() == "");
  }

  stringstream full_list, half_list;
  for (int i = 999; i > 0; i--) {
    full_list << i << ", ";
    if (i < 500)
      half_list << i << ", ";
  }
  full_list << 0;
  half_list << 0;
  for (unsigned int i = 0; i < 1000; i++)
    stack.InsertHead(i);
  SECTION("InsertHead() \"HIGH LOAD\"") {
    CHECK(stack.size() == 1000);
    CHECK(stack.ToString() == full_list.str());
  }

  for (unsigned int i = 0; i < 500; i++) {
    stack.RemoveHead();
  }
  SECTION("RemoveHead() \"HIGH LOAD\" 1/2") {
    CHECK(stack.size() == 500);
    CHECK(stack.ToString() == half_list.str());
  }

  for (unsigned int i = 0; i < 600; i++) {
    stack.RemoveHead();
  }
  SECTION("RemoveHead() \"HIGH LOAD\" 2/2") {
    CHECK(stack.size() == 0);
    CHECK(stack.ToString() == "");
  }
}
