[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Aron Joseph

## Description
My code calculates the MST of a graph represented by an adjacency matrix. In the main file a graph can be 
constructed. The graph class contains a graph constructor which takes in the number of vertecies. The graph's addd 
edge method can be called to add edges and its primmst method can be called to print a mst of the graph in its 
current state. To accomplish this it uses method in the heap class.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | NA              |
| Extract Min          | O(1)            |
| Decrease Key         | O(V)            |
| Prim’s MST Overall   | O(V^2)          |

_Explain why your MST implementation has the above runtime._
In the graph class when PrimMST is called, it goes through all the vertecies O(V). For each vertex, decrease key 
could be called which is O(V) since the minheapify method is called which takes O(V) time complexity since the heap 
array is travered O(V) and the vertex is put in its correct order which at worst is O(V).


## Test Case Description
Assumptions
I assumed that the edges were weighted and undirected.





Test Case Description

Input:
int main() {
Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);
g.primMST();
return 0;

}

Output:
C:\code\DataStructures\programming-assignment-3-Aron-K-Joseph\cmake-build-debug\PA3.exe
1:  0 -> 1 with weight 2.
2:  1 -> 2 with weight 3.
3:  1 -> 4 with weight 5.
4:  0 -> 3 with weight 6.
Sum of edge weight: 16
Process finished with exit code 0

Test Plan

I tried cases where it tries to decrease a key for a vertex that has already been visited.


Challenges Faced (Optional)

Too many difficulties and challenges.
