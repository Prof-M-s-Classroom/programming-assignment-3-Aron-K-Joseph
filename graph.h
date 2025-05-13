#ifndef GRAPH_H
#define GRAPH_H


#include "heap.h"

class Graph {
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
        }
        for (int r = 0; r < vertices; r++) {
            for (int c = 0; c < vertices; c++) {
                if (r == c) {
                    adjMatrix[r][c] = 0;
                }
                else {
                    adjMatrix[r][c] = 2147483647;
                }


                //std::cout<<"r: "<<r<<"        c: "<<c<<"        val: "<<adjMatrix[r][c]<<std::endl;
            }
        }
    };
    //~Graph();
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    };
    void primMST() {
        MinHeap min_heap = MinHeap(numVertices);
        while (!min_heap.isEmpty()) {
            int extractedMin = min_heap.extractMin();
            printf("%da\n",extractedMin);
            for (int i = 0;i<numVertices;i++) {
                if (adjMatrix[i][extractedMin]<2147483647 && adjMatrix[i][extractedMin]!=0) {
                    min_heap.decreaseKey(i,adjMatrix[i][extractedMin]);
                }

            }
        }

    };  // Must print MST edges and total weight
    void printMatrix() {
        for (int r = 0; r < numVertices; r++) {

            for (int c = 0; c < numVertices; c++) {
                printf("%15d",adjMatrix[r][c]);
            }
            printf("\n");
        }
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif