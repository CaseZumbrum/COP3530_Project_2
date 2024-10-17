#include "Adjacency_List.h"
#include <algorithm>

using namespace std;

Adjacency_List::Adjacency_List() {

}

void Adjacency_List::print() {
    for(auto i = this->graph.begin(); i != this->graph.end(); i++){
        cout << this->id_to_name[i->first] << ": ";
        for( int g = 0; g < i->second.size(); g++){
            cout << this->id_to_name[i->second[g]] << ", ";
        }
        cout << endl;
    }
}

bool Adjacency_List::add(string from, string to){
    int from_id;
    int to_id;
    if(this->name_to_id.find(from) == this->name_to_id.end()){

        from_id = this->id_to_name.size();
        this->id_to_name[from_id] = from;
        this->name_to_id[from] = from_id;

    }
    else{
        from_id = this->name_to_id[from];
    }

    if(this->name_to_id.find(to) == this->name_to_id.end()){

        to_id = this->id_to_name.size();
        this->id_to_name[to_id] = to;
        this->name_to_id[to] = to_id;

    }
    else{
        to_id = this->name_to_id[to];
    }

    graph[from_id].push_back(to_id);
    if (graph.find(to_id)==graph.end()) {
        graph[to_id] = {};
    }
    return true;
}

void Adjacency_List::page_rank(int p) {

    vector<float> r;
    for(int i = 0; i < this->graph.size(); i++){
        r.push_back(1.0/this->graph.size());
    }

    for(int g = 0; g < p; g++) {
        vector<float> r_next;

        for (int i = 0; i < this->graph.size(); i++) {
            float sum = 0;
            for (int j = 0; j < this->graph.size(); j++) {
                if (find(this->graph[j].begin(), this->graph[j].end(), i) != this->graph[j].end()) {
                    sum += ((1.0 / this->graph[j].size()) * r[j]);
                }
            }
            r_next.push_back(sum);
        }
        r = r_next;
    }

    cout << "-----------------------" << endl;
    for(int i = 0; i < r.size(); i++){
        cout << r[i] << endl;
    }
}