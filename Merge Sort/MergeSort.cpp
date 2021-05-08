

#include <iostream>
#include <time.h>

using namespace std;


void Merge(int *A, int p, int q, int r) {
	const int n1 = q - p;
	const int n2 = r - q;
	int * L = { new int[n1+1] };
	int * R = { new int[n2+1] };
	int i;
	int j;
	for (i = 0; i < n1; i++)
	{
		L[i] = (A[p + i]);
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = (A[q + j]);
	}
	L[n1] = (numeric_limits<int>::max());
	R[n2] = (numeric_limits<int>::max());
	i = 0;
	j = 0;
	for (int k = p; k < r; k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i = i + 1;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
}


void Merge_Sort(int *A, int p, int r) {

	if (p+1 < r)
	{
		int q = (p + r) / 2;
		Merge_Sort(A, p, q);
		Merge_Sort(A, q, r);
		Merge(A, p, q, r);
	}
}


int main() {
	clock_t start, finish;
	start = clock();
	const int size = 100;
	int * A = { new int[size] };
	for (int i = 0; i < size; i++)
	{
		A[i] = rand() % 1000 + 1;
	}

	Merge_Sort(A, 0, size);
	finish = clock();

	double start2 = (double)(start) / CLOCKS_PER_SEC;
	double finish2 = (double)(finish) / CLOCKS_PER_SEC;
	double duration = (finish2 - start2)*1000;
	cout << duration << " milliseconds" << endl;
	for (int j = 0; j < size; j++)
	{
		cout << endl << A[j];
	}
	cin.get();
	return 0;
}