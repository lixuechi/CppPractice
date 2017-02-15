/*Write a single sum function capable of handling an arbitrary number of integers. 
  It should take two arguments, include a loop, and return an integer. 
  (Hint: What data types can you use to represent an arbitrarily large set of integers in two arguments?) */
#include <iostream >
using namespace std;

int sum(const int *ptr, const int count) {
	int result = 0;

	for(int i = 0; i < count; i++, ptr++) {
		result += *ptr;
	}

	return result;
}

int main() {
	int array[5] = {1, 2, 3, 4, 5};
	cout << sum(array, 5);

	return 0;
}
