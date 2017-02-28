/* Determine whether an integer is a palindrome. Do this without extra space. */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

bool isPalindrome(int x) {
	int number = x;
	int numOfBits = 1;
	for(; number / 10 != 0; numOfBits++, number /= 10);
	
	number = x;
	char *text = new char[numOfBits];
	itoa(number, text, 10);

	for(int i = 0; i < numOfBits / 2; i++) {
		if(text[i] != text[numOfBits - 1 - i]) return false;
	}

	return true;
}

int main() {
	while(1) {
		int integer;
		cin >> integer;
		cout << (isPalindrome(integer) ? "Yes" : "No");
	}

	return 0;
} 
