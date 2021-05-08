#include "LinkedList.h"

const int SIZE = 10;

class Hash
{
private:
	LinkedList myTable[SIZE];
	int hashFunction(int data);
public:
	Hash();
	bool search(int key);
	void insert(int data);
};

