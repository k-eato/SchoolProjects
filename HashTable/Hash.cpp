#include "Hash.h"



Hash::Hash()
{
}

int Hash::hashFunction(int data) {
	return data%SIZE;
}

bool Hash::search(int key) {
	int index = hashFunction(key);
	bool result = myTable[index].search(key);
	if (result == false) {
		cout << "Not in hash table" << endl;
	}
	return result;
}

void Hash::insert(int data) {
	int index = hashFunction(data);
	myTable[index].insertAtBeginning(data);
}