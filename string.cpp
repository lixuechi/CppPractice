/* http://www.cplusplus.com/reference/string/string/ */
#include <iostream >
#include <string> 
using namespace std;

int main() { 
	/* can set strings to normal char *s */
	string s = "Hello";
	s += " world!";
	/* strings can be compared with ==, but char * cannot (because they are pointers), 
	   they are compared with strcmp. */
	if(s == "Hello world!") {
		cout << "Success!" << endl;
	}

	cout << s.substr(6, 6) << endl; // prints "world!"
	cout << s.find("world!") << endl; // prints 6
	/* 5 stands for the starting location for the search */
	cout << s.find("l", 5) << endl; // prints 9

	return 0;
}
