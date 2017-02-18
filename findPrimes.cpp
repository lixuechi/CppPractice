/* Write a program to read a number N from the user and then find the first N primes.
   A prime number is a number that only has two divisors, one and itself. */
#include <iostream>
using namespace std;

bool isPrime(int num) {
	for(int i = 2; i < num; i++) {
		if(num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	while(1) {
		cout << "N = ";
		int N;
		cin >> N;

		int number = 1;
		for(int i = 0; i < N;) {
			if(isPrime(number)) {
				cout << number << endl;
				i++;
			}
			number++;
		}
	}
}
