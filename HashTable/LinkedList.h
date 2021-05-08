#include <iostream>
#include <string>

using namespace std;

class LinkedList {

private:
	struct node {
		int data;
		node* next;
	};

	node* head;
	node* tail;
	int size;   // to keep track of the list size
public:
	LinkedList();
	void insertAtBeginning(const int addData);
	void deleteFromBeginning();
	void deleteKey(const int delData);
	int getSize();
	bool search(int key);
	void displayList();
};