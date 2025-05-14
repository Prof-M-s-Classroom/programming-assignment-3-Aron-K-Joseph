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
        int* extractedMins = new int[numVertices];
        int len=0;

        while (!min_heap.isEmpty()) {
            int extractedMin = min_heap.extractMin();
            extractedMins[len++] = extractedMin;
            for (int i = 0;i<numVertices;i++) {
                if (adjMatrix[i][extractedMin]<2147483647 && adjMatrix[i][extractedMin]!=0) {
                    min_heap.decreaseKey(i,adjMatrix[i][extractedMin],extractedMin);
                }

            }
        }
        //src
        int* keys = min_heap.getKeyArray();
        int* src = min_heap.getheapArraySource();
        // for (int i = 0; i < numVertices; i++) {
        //     printf("%d                                 %d\n",keys[i],src[i]);
        // }




        int** paths = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            paths[i] = new int[2];
            if (i == 0){
                paths[i][0] = 0;
                paths[i][1] = 0;
                paths[i][2] = 0;
            }
            else {
                paths[i][0] = src[i];
                paths[i][1] = i;
                paths[i][2] = keys[i];
            }
        }

        int** orderedPaths = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            int extractedNum = extractedMins[i];
            int index=0;
            while (paths[index][1]!=extractedNum) {
                index++;
            }
            orderedPaths[i] = paths[index];

        }


        int sumWeightEdges = 0;
        for (int i = 1; i< numVertices; i++) {
            sumWeightEdges +=orderedPaths[i][2];
            printf("%d:  %d -> %d with weight %d.\n",i,orderedPaths[i][0],orderedPaths[i][1],orderedPaths[i][2]);
        }
        printf("Sum of edge weight: %d",sumWeightEdges);

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