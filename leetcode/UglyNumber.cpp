/*  Write a program to check whether a given number is an ugly number.
    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
	For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
    Note that 1 is typically treated as an ugly number. */

#include <iostream>
#include <vector>
using namespace std;

bool isUgly(int num) {
	if(num <= 0) return false;

	for(int i = 2; i <= num; i++) {
		if(num % i == 0) { // is factor
			bool isFactorPrime = true;
			for(int j = 2; j < i; j++) {
				if(i % j == 0) {
					isFactorPrime = false;
					break;
				} 
			}
			if(isFactorPrime) {
				if(i != 2 && i != 3 && i != 5)  return false;
			}
		}
	}
	return true;
}

int main() {
	///*
	cout << isUgly(1) << endl;
	cout << isUgly(2) << endl;
	cout << isUgly(3) << endl;
	cout << isUgly(5) << endl;
	cout << isUgly(6) << endl;
	//*/
	cout << isUgly(7) << endl;
	///*
	cout << isUgly(8) << endl;
	cout << isUgly(10) << endl;
	cout << isUgly(14) << endl;
	cout << isUgly(-2147483648) << endl;
	cout << isUgly(905391974) << endl;
	//*/

	return 0;
}
