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

    // from is new
    if(this->name_to_id.find(from) == this->name_to_id.end()){

        from_id = this->id_to_name.size();
        this->id_to_name[from_id] = from;
        this->name_to_id[from] = from_id;

    }
    else{
        from_id = this->name_to_id[from];
    }

    // to is new
    if(this->name_to_id.find(to) == this->name_to_id.end()){

        to_id = this->id_to_name.size();
        this->id_to_name[to_id] = to;
        this->name_to_id[to] = to_id;

    }
    else{
        to_id = this->name_to_id[to];
    }

    // update graph
    this->graph[from_id].push_back(to_id);
    // add to_id to graph
    if (this->graph.find(to_id)==this->graph.end()) {
        this->graph[to_id] = {};
    }
    return true;
}

void Adjacency_List::page_rank(int p) {
    // intialize r
    vector<double> r;
    for(int i = 0; i < this->graph.size(); i++){
        r.push_back(1.0/this->graph.size());
    }

    // for each power iteration
    // p - 1 since the first power iteration happens without any matrix multiplication
    for(int g = 0; g < p-1; g++) {
        // r(t+1)
        vector<double> r_next;

        // for each node in the graph
        for (int i = 0; i < this->graph.size(); i++) {
            double sum = 0;
            // for each node that could be adjacent
            for (int j = 0; j < this->graph.size(); j++) {
                // if the node is adjacent, add it multiplied by the previous r
                // matrix multiplication MxR happens here
                // do not create adjacency matrix, but same effect
                if (find(this->graph[j].begin(), this->graph[j].end(), i) != this->graph[j].end()) {
                    // weight is based on the out degree of j
                    sum += ((1.0 / this->graph[j].size()) * r[j]);
                }
            }
            // update r_next
            r_next.push_back(sum);
        }
        // r(t+1)
        r = r_next;
    }

    // printing r
    cout << "-----------------------" << endl;
    for(int i = 0; i < r.size(); i++){
        cout << this->id_to_name[i] << ": " <<  r[i] << endl;
    }
}