#include <iostream>
using namespace std;

int main() {
	// 3.1
	int arg1;
	arg1 = -1;
	int x, y, z;
	char myDouble = '5';

	{
		char arg1 = 'A';
		cout << arg1 << "\n"; // prints A
	}

	// char arg1 = 'A'; // error: redefinition; different basic types
	cout << arg1 << "\n"; // prints -1

	return 0;
}