#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	LinkedList myList;

	string inputName;
	int choice;
	cout << "1 -- insert at beginning" << endl;
	cout << "2 -- delete from beginning " << endl;
	cout << "3 -- delete key" << endl;
	cout << "4 -- display" << endl;
	cout << "5 -- size" << endl; // to be implemented
	cout << "6 -- EXIT." << endl;

	do {
		cout << "Enter your choice ... " << endl;
		cin >> choice;
		cout << endl;

		switch (choice) {

		case 1:
			cout << "Enter a name:" << endl;
			cin >> inputName;
			cout << endl;
			myList.insertAtBeginning(inputName);
			break;
		case 2:
			myList.deleteFromBeginning();
			break;
		case 3:
			cout << "Enter the name to be deleted: ";
			cin >> inputName;
			cout << endl;
			myList.deleteKey(inputName);
			break;
		case 4:
			myList.displayList();
			break;
		case 5:
			cout << "List size is: " << myList.getSize() << endl;

		}

	} while (choice != 6);

	return 0;
}