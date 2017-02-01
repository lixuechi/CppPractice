/* factorial */
#include <iostream>
using namespace std;

int main() {
	while(1) {
		short number;
		cout << "Enter a number: ";
		cin >> number;

		cout << "The factorial of " << number << " is ";
		int accumulator = number;
		for(; number > 1; accumulator *= -- number);
		cout << accumulator << ".\n";
	}

	return 0;
}