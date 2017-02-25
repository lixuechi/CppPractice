#include <iostream>
using namespace std;

const int DIV_BY_0 = 0;

int divide(const int x, const int y) {
	if(y == 0)
		throw DIV_BY_0;
	return x / y;
}

void f(int x, int **arrPtr) {
	try {
		*arrPtr = new int[divide(5, x)];
	} catch (int error) {
		// cerr is like cout but for error messages
		cerr << "Caught error: " << error << endl;
	}
}

int divide2(const int x, const int y) {
	if(y == 0)
		throw std::runtime_error("Divide by 0!");
	return x / y;
}

void f2(int x, int **arrPtr) {
	try {
		*arrPtr = new int[divide(5, x)];
	} catch (bad_alloc &error) { // new throws exceptions of this type
		cerr << "new failed to allocate memory";
	} catch (runtime_error &error) { 
		/* should always use ref in the argument in a catch clause,
		   this is used to prevent excessive copying and let the proper virtual function
		   to be invoked on the exception object. */
		cerr << "Caught error: " << error.what();
	}
}

int main() {

	return 0;
} 
