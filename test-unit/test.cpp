#include "../src/Adjacency_List.h"
#include "../src/main.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <map>


using namespace std;

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp .\src\Adjacency_List.cpp; ./build/test
*/

TEST_CASE("Page rank with 1 element", "[]"){
    Adjacency_List a;
    a.add("a", "a");

    map<string, double> m = a.page_rank(1);
    map<string, double> correct;
    correct["a"] = 1.00;
    REQUIRE(m == correct);
}

TEST_CASE("Page rank with 0 elements", "[]"){
    Adjacency_List a;

    map<string, double> m = a.page_rank(1);
    map<string, double> correct;

    REQUIRE(m == correct);
}

TEST_CASE("Page rank with all elements pointing to one", "[]"){
    Adjacency_List a;

    a.add("a","a");
    a.add("b","a");
    a.add("c", "a");
    a.add("d","a");

    map<string, double> m = a.page_rank(10);
    map<string, double> correct;
    correct["a"] = 1.00;
    correct["b"] = 0;
    correct["c"] = 0;
    correct["d"] = 0;

    REQUIRE(m == correct);
}