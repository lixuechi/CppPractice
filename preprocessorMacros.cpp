#include <iostream>
using namespace std;

/* #define is a preprocessor command
   it can be used to define macros such as below, or define constants
*/
#define sum(x, y) (x + y)

int main() {
	/* Now, every time sum(a, b) appears in the code, 
	   for any arguments a and b, it will be replaced with (a + b).
	   Macros are like small functions that are not type-checked; 
	   they are implemented by simple textual substitution. 
	   Because they are not type-checked, they are considered less robust than functions.
	*/

	// TODO diff between typedef and #define

	return 0;
} 
