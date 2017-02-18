#include <iostream >
using namespace std;

/* Write a function that returns the length of a string (char *), 
   excluding the final NULL character. 
   It should not use any standard-library functions. 
   You may use arithmetic and dereference operators,but not the indexing operator([]). */
int getStringLength(const char *str) {
	int count = 0;
	for(; *str != NULL; str++, count++); 

	return count;
}

/* Write a function that swaps two integer values using call-by-reference */
void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

/* Write a function that swaps two integer values using ponters */
void swapByPointer(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

/* Write a function that swaps two pointers to point to each other's values */
void swapPtr(int **xPtr, int **yPtr) {
	int temp = **xPtr;
	*xPtr = *yPtr;
	*yPtr = &temp;

	cout << **xPtr << **yPtr << endl;
}

int main() { 
	char *yeah = "yeahwho";
	cout << getStringLength(yeah) << endl;

	int a = 250, b = 38;
	swap(a, b);
	cout << "a=" << a << ",b=" << b << endl;

	int c = 666, d = 419;
	swapByPointer(&c, &d);
	cout << "c=" << c << ",d=" << d << endl;

	int e = 77, f = 88;
	int *ePtr = &e, *fPtr = &f;
	swapPtr(&ePtr, &fPtr);
	cout << "*ePtr=" << *ePtr << ",*fPtr=" << *fPtr << endl;

	char *oddOrEven = "Never odd or even";
	/* Create a pointer to a char value named nthCharPtr pointing to the 6th character of oddOrEven 
	   (remember that the first item has index 0). Use the indexing operator. */
	char *nthCharPtr = &oddOrEven[5];
	/* Using pointer arithmetic,update nthCharPtr to point to the4th character in oddOrEven. */
	nthCharPtr = oddOrEven + 3;
	/* Print the value currently pointed to by nthCharPtr. */
	cout << *nthCharPtr << endl;
	/* Create a new pointer to a pointer (a char **) named pointerPtr that points to nthCharPtr. */
	char **pointerPtr = &nthCharPtr;
	/* Print the value stored in pointerPtr. */
	cout << *pointerPtr << endl;
	/* Using pointerPtr, print the value pointed to by nthCharPtr. */
	cout << **pointerPtr << endl;
	/* Update nthCharPtr to point to the next character in oddOrEven 
	   (i.e. one character past the location it currently points to). */
	nthCharPtr++;
	/* Using pointer arithmetic, print out how far away from the character 
	   currently pointed to by nthCharPtr is from the start of the string. */
	cout << nthCharPtr - oddOrEven << endl;

	return 0;
}
