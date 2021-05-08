#include "PriorityQueue.h"


PriorityQueue::PriorityQueue()
{
}


void PriorityQueue::insert(int data) {
	myHeap.Insert(data);
}

int PriorityQueue::max() {
	return myHeap.viewMax();
}

int PriorityQueue::delMax() {
	return myHeap.Delete();
}

void PriorityQueue::increaseKey(int key, int newData) {
	myHeap.changeKey(key, newData);
}
