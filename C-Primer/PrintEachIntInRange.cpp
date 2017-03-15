/**
   Write a program that prompts the user for two integers.
   Print each number in the range specified by those two integers.
 */
#include <iostream>
using namespace std;

int main() {
	int numA;
	int numB;
	cin >> numA >> numB;
	while(numB < numA)
		cout << numB++;
	while(numA < numB)
		cout << numA++;

	return 0;
} 
