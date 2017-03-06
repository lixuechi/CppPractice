#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

// When using template, a variable's type is very difficult to decide if the variable's type is depending on template types.
template<class T, class U>
void multiply(T t, U u) {
	auto ret = t * u;
}

int main() {
	auto a; // error, auto determines type by initialization
	auto i = 1;
	cout << typeid(i).name() << endl; // under g++ compiler, output int; under MS VS2008, output int
	auto id = 1.0;
	cout << typeid(d).name() << endl; // output double
	auto str = "Hello C++11";
	cout << str << endl;
	
	vector<int> iv;
	iv.push_back(1);
	iv.push_back(2);
	iv.push_back(3);
	
	for(auto itr = iv.begin(); itr != iv.end(); itr++) // automatically deduced to iterator
		cout << *itr << endl;
		
	return 0;
}
