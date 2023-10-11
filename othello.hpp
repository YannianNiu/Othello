#include <cstddef>
#include <cstdint>
#include <string>
#include <iostream>
#include <type_traits>
#include <unordered_set>
#include <array>
#include "graph.hpp"

using namespace std;

#define bitsize 8
#define num_of_vertex 8

class Othello{

public:
    uint32_t ma;
    uint32_t mb;
    std::hash<std::string> h1;
    std::hash<std::string> h2;
    array<int, bitsize> a;
    array<int, bitsize> b;
    Graph<int> graph;

    Othello(Graph<int> graph);
    
    Othello():graph(8){}
    void init();
    void insert(int sub, string str);
    bool preCheck(int firstNode);
};

inline void Othello::init(){
    graph.init();
    a.fill(-1);
    b.fill(-1);
}

inline void Othello::insert(int sub, string str){
    this->graph.insertEdge(this->h1(str)%bitsize, this->h2(str)%bitsize);
    cout<<this->h1(str)%bitsize<<' '<<this->h2(str)%bitsize<<endl;
    int v = 0;
    if(sub == 1)
        v = 0;
    else
        v = 1;
    if(this->a[this->h1(str)%bitsize] == -1 && this->b[this->h2(str)%bitsize] == -1){
        this->a[this->h1(str)%bitsize] = 0;
        this->b[this->h2(str)%bitsize] = 1;
    }else if(this->a[this->h1(str)%bitsize] == -1)
        this->a[this->h1(str)%bitsize] = this->b[this->h2(str)%bitsize] ^ v;
    else
        this->b[this->h2(str)%bitsize] = this->a[this->h1(str)%bitsize] ^ v;
}

inline bool Othello::preCheck(int firstNode){
    this->graph.printadjmatrix();
    return this->graph.DFS(firstNode);
}


