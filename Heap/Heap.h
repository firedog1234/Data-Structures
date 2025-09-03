//
// Created by Avi Patel on 8/27/25.
//
#pragma once

class Heap {
 private:
  int* arr;
  int capacity;
  int size;
  bool isMaxHeap;
  bool (Heap::*comparator)(int parent, int child);
  int (Heap::*compareChildren)(int currentIndex, int leftChild, int rightChild);

  void heapifyUp(int index);
  void heapifyDown(int index);
  bool compareMaxHeap(int parent, int child);
  bool compareMinHeap(int parent, int child);
  int compareChildrenMaxHeap(int currentIndex, int leftChildIndex,
                             int rightChildIndex);
  int compareChildrenMinHeap(int currentIndex, int leftChildIndex,
                             int rightChildIndex);

 public:
  Heap(int cap, bool maxHeap);
  Heap(const Heap& other);
  Heap& operator=(const Heap& other);
  ~Heap();

  void insert(int val);
  int extract();
  int peek() const;
  int getSize() const;
  bool empty() const;
  bool full() const;
  void buildHeap(int* arr, int size);
};
