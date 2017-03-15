/**
   Write a program that uses a while to sum the numbers from 50 to 100.
 */
#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int num = 49;
	while(num++ <= 100) {
		cout << ' ' << num;
		sum += num;
	}
	cout << sum << endl;

	return 0;
} 
