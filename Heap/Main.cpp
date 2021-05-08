#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
	int input;
	Heap myHeap;
	do
	{
		cout << endl << "Pick one of the operations by entering the respective number:" << endl <<
			"1. Insert" << endl << "2. Delete" << endl << "3. Display Heap" << endl << "4. End" << endl;
		cin >> input;
		cout << endl;
		switch (input) {
		case 1:
			int data;
			cout << "Please enter a number: ";
			cin >> data;
			cout << endl;
			myHeap.Insert(data);
			break;
		case 2: 
			myHeap.Delete();
			break;
		case 3: 
			myHeap.Display();
			break;
		}
	} while (input != 4);
	return 0;
}