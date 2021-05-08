
#include  <vector>
#include  <iostream>
#include  <fstream>
#include  <string>

using namespace std;

int main() {

	ifstream file;
	file.open("data.txt");
	int A[] = { 0,0,0,0,0,0,0,0,0};
	int i = 0;
	while (i < 9)
	{
		file >> A[i];
		cout << A[i] << endl;
		i++;
	}		
	cout << endl;
	for (int i = 1; i < size(A); i++)
	{
		int temp = A[i];
		int j = i;
		while (temp < A[j-1] && j>0) {
			A[j] = A[j-1];
			j--;
		}
		A[j] = temp;
	}
	for (int k = 0; k < size(A); k++)
	{
		cout << A[k];
	}

	cin.get();
	return 0;
}
