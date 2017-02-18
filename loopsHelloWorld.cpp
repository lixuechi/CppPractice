#include <iostream>
using namespace std;

/* Write a program that outputs "Hello, World!" n times (where n is a nonnegative integer
   that the user will input) with:
   a for loop.
   a while loop.
   a do...while loop. */

int main() {
	cout << "The number of loops is:" << endl;
	int n = -1;

	while(n < 0) {
		cout << "Please enter a nonnegative integer." << endl;
		cin >> n;
	}

	const char * canonical = "Hello, World!";

	cout << "for loops" << endl;
	for(int i = 0; i < n; i++) {
		cout << canonical << endl;
	}

	cout << endl << "while loop" << endl;
	int j = 0; 
	while(j < n) {
		cout << canonical << endl;
		j++;
	}

	cout << endl << "do while loop" << endl;
	int k = 0; 
	do {
		cout << canonical << endl;
		k++;
	} while (k < n);
}
