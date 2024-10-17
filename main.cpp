#include <iostream>
#include <vector>
#include <map>

#include "Adjacency_List.h"

using namespace std;

int main() {
    int no_lines;
    string from, to;
    cin >> no_lines;
    Adjacency_List a;

    for(int i = 0; i < no_lines; i++)
    {
        cin >> from >> to;
        a.add(from, to);
    }

    a.page_rank(2);
    return 0;
}
