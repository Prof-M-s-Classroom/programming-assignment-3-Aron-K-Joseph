#include <iostream>
#include "graph.h"

int main() {
    int a = 3;
    std::cout<<a<<std::endl;
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 9);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 1);
    //
    g.primMST();
    //g.printMatrix();
    return 0;
}