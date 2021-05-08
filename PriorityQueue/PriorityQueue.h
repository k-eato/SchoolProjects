#pragma once
#include "Heap.h"

class PriorityQueue
{
private:
	Heap myHeap;
public:
	PriorityQueue();
	void insert(int data);
	int max();
	int delMax();
	void increaseKey(int key, int newData);
};