#include <string>
#include <iostream>
using namespace std;

class Integer {
public:
	int val;
	Integer() {
		val = 0; 
		cout << "Integer default constructor." << endl;
	}

	Integer(int val) {
		/* refer to a field when a method argument has the same name */
		this->val = val; // a shorthand for (*this).val
		cout << "Integer constructor with arg " << val << endl;
	}

	/* Destructor is called when the class instance gets de-allocated */
	~Integer() {
		cout << "Integer destructor invoked." << endl;
	}

	/* If a constructor with parameters is defined, 
	   and the default constructor is not defined,
	   the default constructor is no longer available.
	   calling "Integer j;" from main() is an error. */

	void setVal(int val) {
		this->val = val;
	}
};

class IntegerArray {
public:
	int *data;
	int size;

	IntegerArray(int size) {
		data = new int[size];
		this->size = size;
	}

	IntegerArray(IntegerArray &o) {
		data = new int[o.size];
		size = o.size;
		for(int i = 0; i < size; i++) {
			data[i] = o.data[i];
		}
	}

	~IntegerArray() {
		delete[] data;
	}
};

class IntegerWrapper {
public:
	Integer val;
	IntegerWrapper() {
		cout << "IntegerWrapper default constructor." << endl;
	}
};

int *getPtrToFive() {
	int *p = new int;
	*p = 5;
	return p;
}

int main() {
	IntegerWrapper q; // output: Integer default constructor. \n IntegerWrapper default constructor.

	Integer i(3); // output: Integer constructor with arg 3

	/* Can invoke single-parameter constructor via assignment to the appropriate type */
	Integer j = 5; // output: Integer constructor with arg 5

	/* Without a default constructor, can’t declare arrays without initializing */
	Integer a[] = { Integer(2), Integer(3) }; // OK
	//Integer b[2]; // error if without a default constructor

	{
		int x = 5;
	}
	// x now out of scope, memory it used to occupy can be reused

	/* Another way to allocate memory, where the memory will remain allocated 
	   until you manually de-allocate it. */
	/* –If using int x; the allocation occurs on a region of memory called the stack
	   –If using new int; the allocation occurs on a region of memory called the heap */
	int *x = new int;
	/* De-allocates memory that was previously allocated using new */
	delete x;

	int *ptr;
	for(int i = 0; i < 3; i++) {
		ptr = getPtrToFive();
		cout << *ptr << endl;
		delete ptr; // should delete ptr here or there will be a memory leak
		/* only delete if memory is allocated by new */
		/* When your program allocates memory but is unable to de-allocate it, this is a memory leak */
	}

	/* If we use new[] to allocate arrays, they can have variable size,
	   otherwise their size must be a constant.
       De-allocate arrays with delete[] */
	int numItems = 3;
	int *arr = new int[numItems];
	delete[] arr;

	/* new can also be used to allocate a class instance */
	Integer *i1 = new Integer;
	Integer *i2 = new Integer(2);


	IntegerArray arr(2);

	return 0;
}
