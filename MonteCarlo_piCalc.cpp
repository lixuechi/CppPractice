#include <iostream >
#include <stdlib.h>
/* Using Monte Carlo method to calculate pi with the ratio of dart */
#include <time.h>
#include <cmath>
using namespace std;

const int N = 999;

double func(int numOfThrows) {
	double x, y;
	double pi = 0;

	int count = 0;
	srand((int)time(0));
	for(int i = 0; i < numOfThrows; i++) {
		int num1 = rand();
		x = num1 % N * 1.0 / N;
		int num2 = rand();
		y = num2 % N * 1.0 / N;

		if(x * x + y * y <= 1) {
			count++;
		}
	}

	pi = 4 * (count * 1.0 / numOfThrows);

	return pi;
}

int main() {
	cout << func(5000000) << endl;

	return 0;
}
