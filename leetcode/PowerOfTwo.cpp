/*  Given an integer, write a function to determine if it is a power of two.  */

#include <iostream>
#include <vector>
using namespace std;

bool isPowerOfTwo(int n) {
	if(n == 0) return false;
	
	while(!(n & 1)) 
		n >>= 1;
	
	return !(n>>1);
}

int main() {
	cout << isPowerOfTwo(0) << endl;
	cout << isPowerOfTwo(1) << endl;
	cout << isPowerOfTwo(2) << endl;
	cout << isPowerOfTwo(3) << endl;
	cout << isPowerOfTwo(4) << endl;
	cout << isPowerOfTwo(5) << endl;
	cout << isPowerOfTwo(6) << endl;
	cout << isPowerOfTwo(7) << endl;
	cout << isPowerOfTwo(8) << endl;

	return 0;
}
