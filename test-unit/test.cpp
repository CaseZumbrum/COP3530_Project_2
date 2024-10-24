#include "../src/Adjacency_List.h"
#include "../src/main.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <map>
#include <limits>

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

TEST_CASE("Testing normal usage", "[]"){
    Adjacency_List a;

    a.add("a","b");
    a.add("c","d");
    a.add("d", "c");
    a.add("e","f");
    a.add("d","e");
    a.add("f","a");
    a.add("d","g");
    a.add("b","f");
    a.add("e","d");
    a.add("d","f");


    map<string, double> m = a.page_rank(9);
    map<string, double> correct;
    correct["a"] = 0.28243582589285710;
    correct["b"] = 0.19308035714285715;
    correct["c"] = 0.00282505580357143;
    correct["d"] = 0.00282505580357143;
    correct["e"] = 0.00282505580357143;
    correct["f"] = 0.23311941964285712;
    correct["g"] = 0.00282505580357143;

    for(auto i = m.begin(); i != m.end(); i++){
         cout << i->first << " " << fixed << setprecision(numeric_limits<double>::max_digits10) << i->second << endl;
         cout << correct[i->first] << endl;
    }

    REQUIRE(m == correct);
}