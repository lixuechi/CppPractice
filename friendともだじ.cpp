#include <iostream>
using namespace std;

class A {
	/* all member functions of class A should be fully available to class B */
	friend class B;
};

class USCurrency {
	friend ostream &operator <<(ostream &o, const USCurrency &c);
	int dollars, cents;
public:
	USCurrency(const int d, const int c):dollars(d), cents(c) {}
};

ostream &operator <<(ostream &o, const USCurrency &c) {
	o << '$' << c.dollars << '.' << c.cents;
	return o;
}

int main() {

	return 0;
} 
