#include <iostream>

using namespace std;



int search(int *A, int p, int r, int key) {
	if (p > r) {
		return -1;
	}
	int q = (p + r) / 2;
	if (A[q] == key)
	{
		return q;
	}
	else if (A[q] > key)
	{
		search(A, p, q-1, key);
	}
	else if (A[q] < key)
	{
		search(A, q+1, r, key);
	}
}
int main() {
	int A[] = { 1,2,3,4,5,6,7,8, 9, 11 };
	int key =6;
	int p = 0;
	int r = size(A);
	int index = search(A, p, r, key);
	cout << index;
	cin.get();
	return 0;
}