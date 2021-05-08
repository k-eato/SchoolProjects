#include <iostream>
#include "Heap.h"
#include "PriorityQueue.h"

using namespace std;

int main() {

	PriorityQueue myPQ;
	myPQ.insert(7);
	myPQ.insert(4);
	myPQ.insert(2);
	cout << myPQ.max() << endl;

	myPQ.insert(9);
	myPQ.insert(3);
	cout << myPQ.max() << endl;

	myPQ.delMax();
	myPQ.insert(11);
	cout << myPQ.max() << endl;
	

	myPQ.increaseKey(4, 30);
	cout << myPQ.max() << endl;

	cin.get();
	return 1;
}