
#include <iostream>

using namespace std;


int Partition(int A[], int p, int r) {
	int i = p - 1;
	int pivot = A[r];
	int temp;
	for (int j = p; j <= r - 1; j++) {
		if (A[j] > pivot) {
			i++;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	A[r] = A[i+1];
	A[i+1] = pivot;
	return i + 1;
}


void QuickSort(int A[], int p, int r) {
	if (p < r) {
		int q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q+1, r);
	}
}


int main() {

	int array[] = { 1, 2, 7, 3, 8, 4, 9, 8, 2};
	QuickSort(array, 0, size(array)-1);

	for (int k = 0; k < size(array); k++) {
		cout << array[k] << endl;
	}
	cin.get();
	return 0;
}