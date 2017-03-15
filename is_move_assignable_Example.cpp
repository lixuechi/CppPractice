/**
   is_move_assignable example
 */
#include <iostream>
#include <type_traits>
using namespace std;

struct A { };
struct B { B& operator = (B&&) = delete; };

int main() {
	cout << boolalpha;
	cout << "is_move_assignable: " << endl;
	cout << "int: " << is_move_assignable<int>::value << endl;
	cout << "A: " << is_move_assignable<A>::value << endl;
	cout << "B: " << is_move_assignable<B>::value << endl;

	return 0;
} 
