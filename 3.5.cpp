/* returns the multiplication of bob and dole */
#include <iostream>
using namespace std;

#define O 1

int multiply(int bob, int dole) {
	int accumulator = 0;

	while(true) {
		if(dole == 0) break;
		accumulator += ((dole % 2 == 1) ? bob : 0);
		dole /= 2;
		bob *= 2;
	}
	return accumulator;
}

/* minimize N to 1 or -1, depending on whether (N / 2) % 2 == 0. 
int func(int N) {
	// N is a nonnegative integer
	double acc = 0;
	for(int i = 1; i <= N; ++i) {
		double term = (1.0 / i);
		acc += term * term;
		for(int j = 1; j < i; ++j) {
			acc *= -1;
		}
	}
	return acc;
}

int main() {
	return O;
}