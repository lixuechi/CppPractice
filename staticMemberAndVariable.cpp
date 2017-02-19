#include <iostream >
using namespace std;

class CDummy {
private:
	/* static variables should not be initialized in the header files, otherwise it is initialized
	   each time the header file is included.
	   Therefore there should only be the declaration of this static variable. */
	static int n; /* a counter with the number of objects of the class that are currently allocated */
public:
	CDummy() { ++n; }
	~CDummy() { --n; }

	/* Static member functions: associated with the class but do not operate on a particular class instance.
	   Such member functions may not access non-static data members. */
	static int getN() { return n; }
};

/* Should place the initialization of the static variable in a .cpp file.
   There must be a initialization or a linker error would occur. */
/* Notice: n is a private variable but it can be initialized like this outside the class definition. */
int CDummy :: n = 0;

int main() { 
	CDummy a;
	CDummy b[5];
	CDummy* c = new CDummy; // beware of the difference from Java

	/* 2 ways to use a static member function: thru obj.func() and Class::func() */
	cout << a.getN() << endl; // outputs 7
	delete c;
	cout << CDummy :: getN() << endl; // outputs 6

	return 0;
}
