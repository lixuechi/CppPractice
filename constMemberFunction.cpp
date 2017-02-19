#include <iostream >
/* Notice: it is <string> not <string.h>, .h are header files in C. */
#include <string> 
using namespace std;

class Person {
private:
	char *name;
public:
	Person(char *n) { name = n; }
	/* The 2nd const keyword means that this is a const member function.
	   the const keyword is required in both the prototype and the definition.
	   Const member functions only operate on const data members.
	   They return const values. */
	const string& getName() const;
};

const string& Person::getName() const {
	return name;
}

int main() { 
	const Person jesse("Jesse");
	return 0;
}
