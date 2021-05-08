#include <iostream>
#include <string>

using namespace std;

class LinkedList {

private:
	struct node {
		string data;
		node* next;
	};

	node* head;
	node* tail;
	int size;   // to keep track of the list size
public:
	LinkedList();
	void insertAtBeginning(const string addData);
	void deleteFromBeginning();
	void deleteKey(const string delData);
	int getSize();
	void displayList();
};