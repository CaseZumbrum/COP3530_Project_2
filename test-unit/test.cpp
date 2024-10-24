#include "../src/Adjacency_List.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <map>
#include <limits>

using namespace std;

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp .\src\Adjacency_List.cpp; ./build/test
*/

bool compare_map(map<string, double> m1, map<string,double> m2){
    if(m1.size() != m2.size()){
        return false;
    }
    for(auto i = m1.begin(); i != m1.end(); i++){
        if(m2.count(i->first) == 0){
            return false;
        }
        if(fabs(i->second - m2[i->first]) >= 0.005){
            return false;
        }
    }

    return true;
}

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

TEST_CASE("Testing normal usage 1", "[]"){
    Adjacency_List a;

    a.add("a","b");
    a.add("c","d");
    a.add("d","c");
    a.add("e","f");
    a.add("d","e");
    a.add("f","a");
    a.add("d","g");
    a.add("b","f");
    a.add("e","d");
    a.add("d","f");


    map<string, double> m = a.page_rank(9);
    map<string, double> correct;
    correct["a"] = 0.28;
    correct["b"] = 0.19;
    correct["c"] = 0.00;
    correct["d"] = 0.00;
    correct["e"] = 0.00;
    correct["f"] = 0.23;
    correct["g"] = 0.00;

    REQUIRE(compare_map(m,correct));
}


TEST_CASE("Testing normal usage 2", "[]"){
    Adjacency_List a;

    a.add("a","b");
    a.add("b","c");
    a.add("c","a");
    a.add("d","c");
    a.add("d","b");


    map<string, double> m = a.page_rank(100);
    map<string, double> correct;

    correct["a"] = 0.375;
    correct["b"] = 0.375;
    correct["c"] = 0.25;
    correct["d"] = 0.00;


    REQUIRE(compare_map(m,correct));
}