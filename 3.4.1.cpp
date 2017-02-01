/* Write a program that loops indefinitely. In each iteration of the loop, read in an integer N (declared as an int) that 
   is inputted by a user, output N/5 if N is nonnegative and divisible by 5, and -1 otherwise. Use the ternary operator (?:)
   to accomplish this. */
#include <iostream>
using namespace std;

int main() {
	while(1) {
		cout << "N = ";
		int N;
		cin >> N;

		int output = (N >= 0 && N % 5 == 0) ? (N / 5) : -1;
		cout << "\noutput = " << output << endl;
	}
}