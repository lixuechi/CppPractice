#include <iostream>
using namespace std;

/* const_cast to remove or add only the const/volatile qualifiers of an object */
struct A {
	void func() { /* non-const member function */ }
};

void f(const A &a) {
	//a.func(); // error because func() is not a const function
}
/* f(const A &a) should change to below: */
void f2(const A &a) {
	A &ref = const_cast<A&>(a);
	ref.func();
}

int main() {
	/* static_cast for safe and rather portable casts */
	bool b = true;
	int n = static_cast <int> (b);

	// mandatory
	int n = 4;
	void *pv = &n;
	int *p2 = static_cast<int *>(pv);


	/* reinterpret_cast for low-level, unsafe and nonportable casts. */ 
	float f = 10;
	unsigned char *p = reinterpret_cast<unsigned char*>(&f);
	for(int i = 0; i < 4; i++) {
		cout << p[i] << endl;
	}

	/* Use dynamic_cast for conversions that must access the dynamic type
	   of an object and RTTI capability-queries. */
	// dynamic_cast

	return 0;
} 
