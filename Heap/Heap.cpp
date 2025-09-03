//
// Created by Avi Patel on 8/27/25.
//

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Heap.h"

Heap::Heap(int cap, bool maxHeap) {
  arr = new int[cap];
  capacity = cap;
  isMaxHeap = maxHeap;
  maxHeap = maxHeap;
  size = 0;
  if (maxHeap) {
    comparator = compareMaxHeap;
    compareChildren = compareChildrenMaxHeap;
  } else {
    comparator = compareMinHeap;
    compareChildren = compareChildrenMinHeap;
  }
}

Heap::Heap(const Heap& other) {
  capacity = other.capacity;
  isMaxHeap = other.isMaxHeap;
  size = other.size;
  comparator = other.comparator;
  compareChildren = other.compareChildren;
  arr = new int[capacity];
  for (int i = 0; i < size; i++) {
    arr[i] = other.arr[i];
  }
}

Heap& Heap::operator=(const Heap& other) {
  if (this == &other) {
    return *this;
  }
  delete[] arr;
  capacity = other.capacity;
  isMaxHeap = other.isMaxHeap;
  size = other.size;
  comparator = other.comparator;
  compareChildren = other.compareChildren;
  arr = new int[capacity];
  for (int i = 0; i < size; i++) {
    arr[i] = other.arr[i];
  }

  return *this;
}

Heap::~Heap() { delete[] arr; }

int Heap::compareChildrenMaxHeap(int currentIndex, int leftChildIndex,
                                 int rightChildIndex) {
  if (leftChildIndex >= size) {
    return currentIndex;
  } else if (rightChildIndex >= size) {
    if (arr[leftChildIndex] > arr[currentIndex]) {
      return leftChildIndex;
    } else {
      return currentIndex;
    }
  }

  if (arr[leftChildIndex] > arr[rightChildIndex] &&
      arr[leftChildIndex] > arr[currentIndex]) {
    return leftChildIndex;
  } else if (arr[rightChildIndex] > arr[leftChildIndex] &&
             arr[rightChildIndex] > arr[currentIndex]) {
    return rightChildIndex;
  } else {
    return currentIndex;
  }
}

int Heap::compareChildrenMinHeap(int currentIndex, int leftChildIndex,
                                 int rightChildIndex) {
  if (leftChildIndex >= size) {
    return currentIndex;
  } else if (rightChildIndex >= size) {
    if (arr[leftChildIndex] < arr[currentIndex]) {
      return leftChildIndex;
    } else {
      return currentIndex;
    }
  }

  if (arr[leftChildIndex] < arr[rightChildIndex] &&
      arr[leftChildIndex] < arr[currentIndex]) {
    return leftChildIndex;
  } else if (arr[rightChildIndex] < arr[leftChildIndex] &&
             arr[rightChildIndex] < arr[currentIndex]) {
    return rightChildIndex;
  } else {
    return currentIndex;
  }
}

void Heap::heapifyDown(int *arr, int index) {
  bool isComplete = false;
  int currentPos = index;
  int leftChild = 2 * index + 1;
  int rightChild = 2 * index + 2;
  int theIndex;

  while (compareChildren(currentPos, leftChild, rightChild) != currentPos) {
    theIndex = compareChildren(currentPos, leftChild, rightChild);
    swap(arr[currentPos], arr[theIndex]);
    currentPos = theIndex;
    leftChild = 2 * currentPos + 1;
    rightChild = 2 * currentPos + 2;
  }
}

bool Heap::compareMaxHeap(int parent, int child) { return parent >= child; }

bool Heap::compareMinHeap(int parent, int child) { return parent <= child; }

void Heap::heapifyUp(int index) {
  int currentPos = index;
  int parentIndex = floor((currentPos - 1) / 2);

  while (currentPos > 0 && comparator(arr[parentIndex], arr[currentPos])) {
    swap(arr[(currentPos - 1) / 2], arr[currentPos]);
    currentPos = (currentPos - 1) / 2;
    parentIndex = floor((currentPos - 1) / 2);
  }
}

void Heap::insert(int val) {
  size++;
  bool isComplete = false;

  if (capacity == size) {
    capacity *= 2;
    int* newArr = new int[capacity];
    for (int i = 0; i < size - 1; i++) {
      newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    newArr = nullptr;
  }

  if (size == 1) {
    arr[0] = val;
  } else {
    arr[size - 1] = val;
    int currentPos = size - 1;
    heapifyUp(currentPos);
  }
}

int Heap::extract() {
  if (size == 0) {
    return -1;
  }
  else if (size == 1) {
    size--;
    return arr[0];
  }
  int place = arr[0];
  swap(arr[0], arr[size - 1]);
  size--;
  heapifyDown(this->arr, 0);
  return place;
}

int Heap::peek() const { return arr[0]; }

int Heap::getSize() const { return size; }

bool Heap::empty() const { return size == 0; }

bool Heap::full() const { return size == capacity; }

void Heap::buildHeap(int* ar, int size) {
  int startIndex = (size - 1) / 2;

  for (int i = startIndex; i >= 0; i--) {
    heapifyDown(ar, i);
  }
}
