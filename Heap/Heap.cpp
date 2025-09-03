//
// Created by Avi Patel on 8/27/25.
//

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;


#include "Heap.h"

Heap::Heap(int cap, bool maxHeap){
  arr = new int[cap];
  capacity = cap;
  isMaxHeap = maxHeap;
  maxHeap = maxHeap;
  size = 0;
  if(maxHeap) {
    comparator = compareMaxHeap;
    compareChildren = compareChildrenMaxHeap;
  } else {
    comparator = compareMinHeap;
    compareChildren = compareChildrenMinHeap;
  }
}

Heap::~Heap(){
  delete[] arr;
}

int Heap::compareChildrenMaxHeap(int currentIndex, int leftChildIndex, int rightChildIndex) {
  if (leftChildIndex >= size) {
    return currentIndex;
  }
  else if (rightChildIndex >= size) {
    if (arr[leftChildIndex] > arr[currentIndex]) {
      return leftChildIndex;
    }
    else {
      return currentIndex;
    }
  }

  if (arr[leftChildIndex] > arr[rightChildIndex] && arr[leftChildIndex] > arr[currentIndex]) {
    return leftChildIndex;
  }
  else if (arr[rightChildIndex] > arr[leftChildIndex] && arr[rightChildIndex] > arr[currentIndex]) {
    return rightChildIndex;
  }
  else {
    return currentIndex;
  }
}

int Heap::compareChildrenMinHeap(int currentIndex, int leftChildIndex, int rightChildIndex) {
  if (leftChildIndex >= size) {
    return currentIndex;
  }
  else if (rightChildIndex >= size) {
    if (arr[leftChildIndex] < arr[currentIndex]) {
      return leftChildIndex;
    }
    else {
      return currentIndex;
    }
  }

  if (arr[leftChildIndex] < arr[rightChildIndex] && arr[leftChildIndex] < arr[currentIndex]) {
    return leftChildIndex;
  }
  else if (arr[rightChildIndex] < arr[leftChildIndex] && arr[rightChildIndex] < arr[currentIndex]) {
    return rightChildIndex;
  }
  else {
    return currentIndex;
  }
}

void Heap::heapifyDown(int index) {
  bool isComplete = false;
  int currentPos = index;
  int leftChild = 2*index + 1;
  int rightChild = 2*index + 2;
  int theIndex;

  while (compareChildren(currentPos, leftChild, rightChild) != currentPos) {
    theIndex = compareChildren(currentPos, leftChild, rightChild);
    swap(arr[currentPos], arr[theIndex]);
    currentPos = theIndex;
    leftChild = 2*currentPos + 1;
    rightChild = 2*currentPos + 2;
  }
}

bool Heap::compareMaxHeap(int parent, int child) {
  return parent >= child;
}

bool Heap::compareMinHeap(int parent, int child) {
  return parent <= child;
}

void Heap::heapifyUp(int index) {
  int currentPos = index;
  int parentIndex = floor((currentPos - 1)/2);

  while(currentPos > 0 && comparator(arr[parentIndex], arr[currentPos])) {
    swap(arr[(currentPos - 1) / 2], arr[currentPos]);
    currentPos = (currentPos - 1) / 2;
    parentIndex = floor((currentPos - 1)/2);
  }
}

void Heap::insert(int val){
  size++;
  bool isComplete = false;

  if(capacity == size){
    capacity *= 2;
    int* newArr = new int[capacity];
    for(int i = 0; i < size - 1; i++){
      newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    newArr = nullptr;
  }

  if (size == 1) {
    arr[0] = val;
  }
  else {
    arr[size - 1] = val;
    int currentPos = size - 1;
    heapifyUp(currentPos);
  }
}

int Heap::extract(){

}






