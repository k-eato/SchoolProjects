#include "LinkedList.h"



// initialize head and tail pointers to NULL
LinkedList::LinkedList() {

	head = NULL;
	tail = NULL;
}

// to add a node at the beginning, we have two cases:
// 1. Empty list and 2. Non-empty list.
// if the list is empty we need to update both pointers head and tail.

void LinkedList::insertAtBeginning(const int addData) {

	node* newNode = new node;
	newNode->data = addData;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
}



void LinkedList::deleteFromBeginning() {

	if (head == NULL)
		cout << "Empty list" << endl;
	else {
		node* delPtr = head;
		head = head->next;
		delete delPtr;
	}

	// what if we have a single node in the linked list??

}

// to delete a node at random location, we need two pointers: one pointer
// to mark the node to be deleted, and one pointer to mark the node before
// the node to be deleted. The two pointers will point to two consecutive nodes.

void LinkedList::deleteKey(const int delData) {

	node* temp;
	node* curr;
	curr = head;
	temp = head;
	while (curr != NULL && curr->data != delData) {
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL)
		cout << "Key is not in the list" << endl;
	else {
		temp->next = curr->next;
		if (curr == head)  // first node to be deleted => update head
			head = head->next;

		delete curr; // to free to memory used by the deleted node
	}
}

// get the number of elements in the list
int LinkedList::getSize() {
	return size;
}

// create a temporary pointer and traverse the entire list
// do not use head pointer.

void LinkedList::displayList() {

	node* curr = head;

	while (curr != NULL) {
		cout << "(" << curr->data << ") -> ";
		curr = curr->next;
	}
	cout << "00" << endl;
}

bool LinkedList::search(int key) {
	node* curr = head;
	while (curr != NULL && curr->data != key) {
		curr = curr->next;
	}
	if (curr == NULL) {
		return false;
	}
	else return true;
}

