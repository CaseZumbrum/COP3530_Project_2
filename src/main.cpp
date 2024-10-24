#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include "Adjacency_List.h"

using namespace std;

int main() {
    int no_lines;
    int p;
    string from, to;
    cin >> no_lines >> p;
    Adjacency_List a;

    for(int i = 0; i < no_lines; i++)
    {
        cin >> from >> to;
        a.add(from, to);
    }

    map<string,double> m = a.page_rank(p);

    for(auto i = m.begin(); i != m.end(); i++){
//        cout << i->first << " " << fixed << setprecision(2) << i->second << endl;
        cout << i->first << " " << i->second << endl;

    }
    return 0;
}
