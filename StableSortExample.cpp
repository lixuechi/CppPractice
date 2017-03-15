/**
   stable sort example
   preserves the relative order of the elements with equivalent values.
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* the way to explicitly convert double to int */
bool compare_as_ints (double i, double j) {
	return (int(i) < int(j));
}

int main() {
	double mydoubles[] = {3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58};

	vector<double> myvector;
	myvector.assign(mydoubles, mydoubles + 8);

	cout << "using default comparison: ";
	stable_sort(myvector.begin(), myvector.end());
	for(vector<double>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	myvector.assign(mydoubles, mydoubles + 8);
	cout << "using 'compare_as_ints' ";
	stable_sort(myvector.begin(), myvector.end(), compare_as_ints);
	for(vector<double>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	return 0;
} 
