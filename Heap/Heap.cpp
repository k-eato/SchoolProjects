#include "Heap.h"
#include <iostream>

using namespace std;


Heap::Heap()
{
	array[0] = 0;
}

void Heap::Insert(int newData) {
	array[0]++;
	array[array[0]] = newData;
	heapifyChild(array[0]);
}

int Heap::Delete() {
	int temp = array[1];
	array[1] = array[array[0]];
	array[0]--;
	heapifyParent(1);
	return temp;
}

void Heap::heapifyParent(int index) {
	int newIndex = index;
	int largest = array[index];
	int left = getChildLeft(index);
	int right = getChildRight(index);

	if (left <= array[0] && array[left] > largest) {
		largest = array[left];
		newIndex = left;
	}
	if (right <= array[0] && array[right] > largest) {
		largest = array[right];
		newIndex = right;
	}
	array[newIndex] = array[index];
	array[index] = largest;
	if (newIndex != index) {
		heapifyParent(newIndex);
	}
}

void Heap::heapifyChild(int index) {
	int parent = getParent(index);

	if (parent != 0 && array[parent] < array[index]) {
		int temp = array[parent];
		array[parent] = array[index];
		array[index] = temp;
		heapifyChild(parent);
	}
}

int Heap::getChildLeft(int index) {
	return index * 2;
}

int Heap::getChildRight(int index) {
	return index * 2 + 1;
}

int Heap::getParent(int index) {
	return index / 2;
}

void Heap::Display() {
	for (int i=1; i <= array[0]; i++) {
		cout << array[i] << endl;
	}
}