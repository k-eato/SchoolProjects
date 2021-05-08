#include <iostream>
#include "Hash.h"

using namespace std;

int main() {

	Hash myHashy;
	myHashy.insert(8909);
	myHashy.insert(4234);
	myHashy.insert(8909);
	myHashy.insert(555);
	myHashy.insert(6512);
	myHashy.insert(61);
	myHashy.insert(70);
	myHashy.insert(36162);
	bool result = myHashy.search(61);

	cout << result << endl;


	cin.get();
	return 0;
}