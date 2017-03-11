/**
   Comments.
 */
#include <iostream>
using namespace std;

int main() {
	cout << "/*" << endl;
	cout << "*/" << endl;
	//cout << /* "*/" */ << endl; // not legal
	cout << /* "*/" /* "/*" */;

	return 0;
} 
