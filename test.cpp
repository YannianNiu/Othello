#include<iostream>
#include <cstdint>
#include "othello.hpp"


using namespace std;

int main(){

    /*
    int num_of_vertex = 8;
    Graph<int> graph(num_of_vertex);

    graph.init();
    graph.insertEdge(1, 0);
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 3);
    graph.insertEdge(4, 2);
    graph.insertEdge(6, 5);

    graph.printadjmatrix();
    cout<<graph.DFS(1)<<endl;
    */
    
    Othello othello;
    othello.init();

    othello.insert(1, "k0");
    othello.insert(0, "k1");
    othello.insert(0, "k2");
    othello.insert(1, "k3");
    othello.insert(1, "k4");

    if(!othello.preCheck(1))
        return 0;
    else
        cout<<"No cycle"<<endl;
}