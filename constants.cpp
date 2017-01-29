#include <iostream>

using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

int main() {
	double r = 5.0;
	double circle;

	circle = 2 * PI * r;
	cout << circle << NEWLINE;

	// this code outputs 0 to 9
	for(int i = 0; i < 10;) {
		cout << i++ << "\n";
	}

	// this code outputs 1 to 10
	for(int i = 0; i < 10;) {
		cout << ++i << "\n";
	}

	// implicit type conversions:
	// float to double
	float f = 5.0;
	double d = f;
	// int to float
	int i = 2;
	f = i;
	// short to long
	short s = 7;
	long l = s;
	// explicit type conversions:
	// int to short
	s = (short)i;
	// float to int
	i = (int)f;

	// ternary operator (?:)
	int a = 2;
	int b = 3;
	int x = 4;
	int y = 5;
	int result = a > b ? x : y;

	return 0;
}