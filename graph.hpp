#include <stdio.h>
#include <iostream>
#include <type_traits>
#include <variant>
#define maxsize 100

using namespace std;

template <typename T>
class Graph
{
    public:
    int numvertex=8;
    T data[maxsize];
    int adjmatrix[maxsize][maxsize];
    bool visited[maxsize];
    void insertEdge(T a, T b);
    bool DFS(int vertex);
    void init();
    void printadjmatrix();   
    void deletenode(T a, T b);
    Graph(int vertex_num);
};


template<typename T>
Graph<T>::Graph(int vertex_num){
    this->numvertex = vertex_num;
}


template<typename T>
void Graph<T>::init(){
    for(int i = 0; i < this->numvertex;i++){
        for(int j = 0; j < this->numvertex; j++){
            adjmatrix[i][j] = 0;
        }
    }
    for(int i = 0; i < this->numvertex; i++)
        visited[i] = 0;
} 

template <typename T>
void Graph<T>::insertEdge(T a, T b){
    adjmatrix[a][b] = 1;
}

template<typename T>
void Graph<T>::deletenode(T a, T b){

}

template<typename T>
bool Graph<T>::DFS(int vertex){
    visited[vertex] = true;
    for(int i = 0; i < this->numvertex; i++){
        if(adjmatrix[vertex][i]!=0 && visited[i])
            return false;
        else if(adjmatrix[vertex][i]!=0 && (!visited[i])){
            visited[i] = 1;
            DFS(vertex);
        }
            
    }
    return true;
}

template <typename T>
void Graph<T>::printadjmatrix()
{
    for (int i = 0; i < this->numvertex; i++)
    {
        for (int j = 0; j < this->numvertex; j++)
        {
            cout<<adjmatrix[i][j]<<"   ";
        }
        cout<<endl;
    }   
}