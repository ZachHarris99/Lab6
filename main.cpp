/**
*	@author Zach Harris
*	@date 10-31-18
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedListOfInts.h"

/////////////////////////////////
//			Constructor
/////////////////////////////////
TEST_CASE("Constructor works")
{
	LinkedListOfInts myList;
	REQUIRE(myList.size() == 0);
	REQUIRE(myList.isEmpty() == true);
}

/////////////////////////////////
//			addFront
/////////////////////////////////
TEST_CASE("addFront should add 1 value to an empty list")
{
	LinkedListOfInts myList;
	std::vector<int> myVec{-2};
	myList.addFront(-2);
	REQUIRE(myList.toVector() == myVec);
}

TEST_CASE("addFront should add 1 value to the front of a list")
{
	LinkedListOfInts myList;
	std::vector<int> myVec{-1, 2};
	myList.addFront(2);
	myList.addFront(-1);
	REQUIRE(myList.toVector() == myVec);
	myVec = {0, -1, 2};
	myList.addFront(0);
	REQUIRE(myList.toVector() == myVec);
}

TEST_CASE("addFront should increment the size by one")
{
	LinkedListOfInts myList;
	myList.addFront(-2);
	REQUIRE(myList.size() == 1);
	myList.addFront(-2);
	REQUIRE(myList.size() == 2);
}

/////////////////////////////////
//			addBack
/////////////////////////////////
TEST_CASE("addBack should add 1 value to an empty list")
{
	LinkedListOfInts myList;
	std::vector<int> myVec{-2};
	myList.addBack(-2);
	REQUIRE(myList.toVector() == myVec);
}

TEST_CASE("addBack should add 1 value to the back of a list")
{
	LinkedListOfInts myList;
	std::vector<int> myVec{1, 2};
	myList.addBack(1);
	myList.addBack(2);
	REQUIRE(myList.toVector() == myVec);
	myVec = {1, 2, 0};
	myList.addBack(0);
	REQUIRE(myList.toVector() == myVec);
}

TEST_CASE("addBack should increment the size by one")
{
	LinkedListOfInts myList;
	myList.addBack(2147000000);
	REQUIRE(myList.size() == 1);
	myList.addBack(0);
	REQUIRE(myList.size() == 2);
}

/////////////////////////////////
//			removeFront
/////////////////////////////////
TEST_CASE("removeFront should return false and do nothing to the list if it's empty")
{
	LinkedListOfInts myList; 
	REQUIRE(myList.removeFront() == false);
	std::vector<int> myVec;
	REQUIRE(myList.toVector() == myVec);
}

TEST_CASE("removeFront should return true if the list is not empty")
{
	LinkedListOfInts myList; 
	myList.addFront(-3202012);
	REQUIRE(myList.removeFront() == true);
}

TEST_CASE("removeFront on a list with one value should result in an empty list")
{
	LinkedListOfInts myList; 
	myList.addFront(-3202012);
	myList.removeFront();
	std::vector<int> myVec;
	REQUIRE(myList.toVector() == myVec);
}

TEST_CASE("removeFront on a list with multiple values should remove the integer in the front of the list")
{
	LinkedListOfInts myList; 
	myList.addFront(-3202012);
	myList.addFront(1);
	myList.addFront(0);
	myList.removeFront();
	std::vector<int> myVec{1, -3202012};
	REQUIRE(myList.toVector() == myVec);
}

TEST_CASE("removeFront should decrement the size of the list")
{
	LinkedListOfInts myList;
	myList.addFront(51);
	myList.addBack(-12);
	REQUIRE(myList.size() == 2);
	myList.removeFront();
	REQUIRE(myList.size() == 1);
}

/////////////////////////////////
//			removeBack
/////////////////////////////////
TEST_CASE("removeBack should return false and do nothing to the list if it's empty")
{
	LinkedListOfInts myList; 
	REQUIRE(myList.removeBack() == false);
	std::vector<int> myVec;
	REQUIRE(myList.toVector() == myVec);
}

TEST_CASE("removeBack should return true if the list is not empty")
{
	LinkedListOfInts myList; 
	myList.addFront(-3202012);
	REQUIRE(myList.removeBack() == true);
}

TEST_CASE("removeBack on a list with one value should result in an empty list")
{
	LinkedListOfInts myList; 
	myList.addFront(-3202012);
	myList.removeBack();
	std::vector<int> myVec;
	REQUIRE(myList.toVector() == myVec);
}

TEST_CASE("removeBack on a list with multiple values should remove the integer in the front of the list")
{
	LinkedListOfInts myList; 
	myList.addFront(-3202012);
	myList.addFront(1);
	myList.addFront(0);
	myList.removeBack();
	std::vector<int> myVec{0, 1};
	REQUIRE(myList.toVector() == myVec);
}

/////////////////////////////////
//			isEmpty
/////////////////////////////////
TEST_CASE("isEmpty should return true if the list has no values")
{
	LinkedListOfInts myList;
	REQUIRE(myList.isEmpty() == true);
}

TEST_CASE("isEmpty should return false if list has one value")
{
	LinkedListOfInts myList;
	myList.addFront(-155);
	REQUIRE(myList.isEmpty() == false);
}

TEST_CASE("isEmpty should return false if list has more than one value")
{
	LinkedListOfInts myList;
	myList.addFront(2);
	myList.addFront(100);
	REQUIRE(myList.isEmpty() == false);
}

/////////////////////////////////
//			size
/////////////////////////////////
TEST_CASE("size should return 0 if the list is empty")
{
	LinkedListOfInts myList;
	REQUIRE(myList.size() == 0);
}

TEST_CASE("size should return the length of the list if it's not empty")
{
	LinkedListOfInts myList;
	myList.addFront(1);
	myList.addBack(1);
	REQUIRE(myList.size() == 2);
	myList.removeBack();
	REQUIRE(myList.size() == 2);//Since removeBack doesn't actually remove an integer, the size should still be 2
}

/////////////////////////////////
//			search
/////////////////////////////////
TEST_CASE("search should return false if the list is empty")
{
	LinkedListOfInts myList;
	REQUIRE(myList.search(50) == false);
	REQUIRE(myList.search(-10) == false);
	REQUIRE(myList.search(0) == false);
}

TEST_CASE("search should return false if the value is not in the list")
{
	LinkedListOfInts myList;
	myList.addFront(100);
	myList.addFront(49);
	myList.addBack(-12);
	myList.addBack(-1);
	myList.addFront(6);
	REQUIRE(myList.search(50) == false);
	REQUIRE(myList.search(-10) == false);
	REQUIRE(myList.search(0) == false);
}

TEST_CASE("search should return true if the value is in the list")
{
	LinkedListOfInts myList;
	myList.addFront(100);
	myList.addFront(49);
	myList.addBack(-12);
	myList.addBack(-1);
	myList.addFront(6);
	REQUIRE(myList.search(100) == true);
	REQUIRE(myList.search(49) == true);
	REQUIRE(myList.search(-12) == true);
	REQUIRE(myList.search(6) == true);
	REQUIRE(myList.search(-1) == true);
}