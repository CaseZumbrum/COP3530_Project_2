#include "../src/Adjacency_List.h"
#include "../src/main.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>

using namespace std;

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp .\src\AVL.cpp .\src\Node.cpp; ./build/test
*/

TEST_CASE("Insert 100 elements, ensure order", "[Insertion]"){
    Adjacency_List a;
    a.add("from", "to");
}