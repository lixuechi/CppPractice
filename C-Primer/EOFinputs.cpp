/**
   Reading an Unknown Number of Inputs
 */
#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int val = 0;
	/* use EOF to stop reading (Ctrl z return) */
	while(cin >> val)
		sum += val;
	cout << "sum = " << sum << endl;

	return 0;
} 
