//
// Created by casez on 10/17/2024.
//

#pragma once

#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Adjacency_List{

    map<int, vector<int>> graph;
    map<int, string> id_to_name;
    map<string, int> name_to_id;

public:
    Adjacency_List();
    bool add(string from, string to);
    void print();
    map<string, double> page_rank(int p);
};