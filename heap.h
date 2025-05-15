#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capcity) {
        capacity = capcity;
        heapArraySource = new int[capacity];
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];
        visited = new int[capacity];

        visitedSize = 0;

        size = capcity;
        for (int i = 0; i<capacity;i++) {
            heapArray[i] = i;
            keyArray[i] = 2147483647;
            position[i] = i;
        }
        keyArray[0] = 0;

    };
    ~MinHeap() {
        delete heapArraySource;
        delete heapArray;
        delete position;
        delete visited;
        delete keyArray;

    };

    int* getheapArraySource() {
        int* ret= new int[capacity];
        for (int i = 0; i<capacity;i++) {
            ret[i] = heapArraySource[i];
        }
        return ret;

    }
    int* getKeyArray() {
        int* ret= new int[capacity];
        for (int i = 0; i<capacity;i++) {
            ret[i] = keyArray[i];
        }
        return ret;

    }
    void insert(int vertex, int key) {

    };

    int extractMin() {
        int tempArraySize = size-1;
        int toReturn = heapArray[0];
        int* tempArray = new int[tempArraySize];
        for (int i = 1;i<size;i++) {
            tempArray[i-1] = heapArray[i];
        }

        heapArray = tempArray;
        size--;
        for(int i = 0; i< capacity;i++){
            if(position[i] != 0){
                position[i] = position[i]-1;
            }
        }
        visited[visitedSize++] = toReturn;
        return toReturn;
    };


    void decreaseKey(int vertex, int newKey,int src) {
        int oldVal = keyArray[vertex];
        if (oldVal>newKey && !(isInVisited(vertex))) {
            keyArray[vertex] = newKey;
            heapArraySource[vertex] = src;
            //printf("Vertex:%d   NewKey:%d    Source:%d\n",vertex,newKey,src);
        }
        minHeapify(vertex);
    };


    bool isInMinHeap(int vertex) {
        for (int i = 0; i < size; i++) {
            if (heapArray[i] == vertex) {
                return true;
            }

        }
        return false;
    };
    bool isInVisited(int vertex) {
        for (int i = 0; i < capacity; i++) {
            if (visited[i] == vertex) {
                return true;
            }

        }
        return false;
    };
    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;

    };

private:
    int* heapArraySource;
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int* visited;
    int capacity;
    int size;
    int visitedSize;

    void minHeapify(int idx) {
        int indexInTheHeapArray = 0;
        for(int i = 0; i< size;i++){
            if(heapArray[i] == idx){
                indexInTheHeapArray = i;
            }
        }
        bool heapArrayUnOrdered = true;
        while(heapArrayUnOrdered){
            int indexOfChild1 = 2*(indexInTheHeapArray)+1;
            int indexOfChild2 = 2*(indexInTheHeapArray)+2;
            int indexOfParent = (indexInTheHeapArray-1)/2;

            if(!(indexOfChild1>=size)) {
                if (keyArray[heapArray[indexInTheHeapArray]]>keyArray[heapArray[indexOfChild1]]){
                    int temp1 = heapArray[indexInTheHeapArray];
                    int temp2 = heapArray[indexOfChild1];

                    heapArray[indexOfChild1] = temp1;
                    heapArray[indexInTheHeapArray] = temp2;


                    int postemp1 = position[temp1];
                    int postemp2 = position[temp2];

                    position[temp1] = postemp2;
                    position[temp2] = postemp1;

                    indexInTheHeapArray = indexOfChild1;
                    continue;



                }
            }

            if(!(indexOfChild2>=size)) {
                if (keyArray[heapArray[indexInTheHeapArray]]>keyArray[heapArray[indexOfChild2]]){
                    int temp1 = heapArray[indexInTheHeapArray];
                    int temp2 = heapArray[indexOfChild2];

                    heapArray[indexOfChild1] = temp1;
                    heapArray[indexInTheHeapArray] = temp2;


                    int postemp1 = position[temp1];
                    int postemp2 = position[temp2];

                    position[temp1] = postemp2;
                    position[temp2] = postemp1;

                    indexInTheHeapArray = indexOfChild2;

                    continue;
                }
            }

            if (size>0) {
                if(keyArray[heapArray[indexInTheHeapArray]]<keyArray[heapArray[indexOfParent]]){
                    int temp1 = heapArray[indexInTheHeapArray];
                    int temp2 = heapArray[indexOfParent];

                    heapArray[indexOfParent] = temp1;
                    heapArray[indexInTheHeapArray] = temp2;


                    int postemp1 = position[temp1];
                    int postemp2 = position[temp2];

                    position[temp1] = postemp2;
                    position[temp2] = postemp1;

                    indexInTheHeapArray = indexOfParent;
                    continue;

                }
            }


            heapArrayUnOrdered = false;

        }

    };
};

#endif