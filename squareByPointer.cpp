// an example of using pointers to square a number in a similar fashion to pass-by-reference
#include <iostream >
using namespace std;

void squareByPtr(int *numPtr) {
	*numPtr = *numPtr * *numPtr;
}

int main() {
	int x = 5;
	squareByPtr(&x);
	cout << x; // prints 25

	return 0;
}
