/*  Write a program to check whether a given number is an ugly number.
    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
	For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
    Note that 1 is typically treated as an ugly number. */

#include <iostream>
#include <vector>
using namespace std;

bool isUgly(int num) {
	if(num == 1) return true; 

	vector<int> primeFactors;
	bool isNumPrime = true;
	for(int i = 2; i < num; i++) {
		if(num % i == 0) { // is factor
			isNumPrime = false;
			// determine whether the factor is prime
			bool isFactorPrime = true;
			for(int j = 2; j < i; j++) {
				if(i % j == 0) {
					isFactorPrime = false;
					break;
				} 
			}
			if(isFactorPrime) primeFactors.push_back(i);
		}
	}

	if(isNumPrime) {
		if(num != 2 && num != 3 && num != 5)
			return false;
		else
			return true;
	}

	bool isInclude235 = false;
	for(vector<int>::iterator it = primeFactors.begin(); it != primeFactors.end(); it++) {
		cout << ' ' << *it;
		
		if(*it == 2 || *it == 3 || *it == 5)
			isInclude235 = true;
		else
			return false;
			
	}
	return isInclude235;
}

int main() {
	//cout << isUgly(1) << endl;
	cout << isUgly(2) << endl;
	//cout << isUgly(3) << endl;
	//cout << isUgly(5) << endl;
	//cout << isUgly(6) << endl;
	//cout << isUgly(8) << endl;
	//cout << isUgly(10) << endl;
	//cout << isUgly(14) << endl;

	return 0;
}
