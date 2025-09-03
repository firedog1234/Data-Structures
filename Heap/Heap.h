//
// Created by Avi Patel on 8/27/25.
//

#ifndef HEAP_H
#define HEAP_H

class Heap {
private:
    int* arr;           // dynamic array for heap elements
    int capacity;       // max size of heap
    int size;           // current number of elements
    bool isMaxHeap;     // true = max-heap, false = min-heap
    bool (Heap::*comparator)(int parent, int child);
    int (Heap::*compareChildren)(int currentIndex, int leftChild, int rightChild);

    void heapifyUp(int index);     // internal: fix heap after insert
    void heapifyDown(int index);   // internal: fix heap after remove
    bool compareMaxHeap(int parent, int child);
    bool compareMinHeap(int parent, int child);
    int compareChildrenMaxHeap(int currentIndex, int leftChildIndex, int rightChildIndex);
    int compareChildrenMinHeap(int currentIndex, int leftChildIndex, int rightChildIndex);

public:
    // Rule of Three
    Heap(int cap, bool maxHeap);      // constructor
    Heap(const Heap& other);                 // copy constructor
    Heap& operator=(const Heap& other);      // copy assignment
    ~Heap();                                 // destructor

    // Core heap operations
    void insert(int val);    // insert a value
    int extract();           // remove root (max or min depending on type)
    int peek() const;        // return root without removing
    int getSize() const;     // return current number of elements
    bool empty() const;      // check if heap is empty
    bool full() const;        // optional: check if heap is full
    void buildHeap(int *arr);
};

#endif
