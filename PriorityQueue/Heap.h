
#pragma once
int const SIZE = 129;

class Heap
{
private:
	int heapSize;
	int array[SIZE];
	void heapifyParent(int index);
	void heapifyChild(int index);
	int getChildLeft(int index);
	int getChildRight(int index);
	int getParent(int index);
public:
	Heap();
	void Insert(int newData);
	int Delete();
	void Display();
	int viewMax();
	void changeKey(int key, int newData);
};

