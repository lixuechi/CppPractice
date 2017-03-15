/**
   partial sort example
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// the return type is either bool or a type that can be converted to bool
int myfunction(int i, int j) { return (i < j); };

int main() {
	int myints[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int> myvector(myints, myints + 9);

	/* the result shows that it's not a sort on just the first N elements */
	partial_sort(myvector.begin(), myvector.begin() + 3, myvector.end());
	for(vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << endl;
	// 1 2 3 9 8 7 6 5 4

	myvector.assign(myints, myints + 9);
	partial_sort(myvector.begin(), myvector.begin() + 7, myvector.end(), myfunction);
	for(vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << endl;
	// 1 2 3 4 5 6 7 9 8

	return 0;
} 
