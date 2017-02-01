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

		// 3.4.1
		int output = (N >= 0 && N % 5 == 0) ? (N / 5) : -1;
		cout << "\noutput = " << output << endl;

		/* 3.4.2 Modify the code from 3.4.1 so that if the condition fails, nothing is printed. Use an if and a continue command
		   (instead of the ternary operator) to accomplish this.
		   3.4.3 Modify the code from 3.4.2 to let the user break out of the loop by entering -1 or any negative number. Before
		   the program exits, output the string "Goodbye!". */
		if(N >= 0 && N % 5 == 0) {
			cout << "output = " << N / 5 << endl;
			continue;
		} else if (N < 0) {
			cout << "Goodbye!" << endl;
			break;
		}
	}
}