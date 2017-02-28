
Skip to content
This repository

    Pull requests
    Issues
    Gist

    @lixuechi

1
0

    0

lixuechi/CppPractice
Code
Issues 0
Pull requests 0
Projects 0
Wiki
Pulse
Graphs
Settings
CppPractice/STLexample01.cpp
599bcb0 2 days ago
@lixuechi lixuechi Create STLexample01.cpp
47 lines (40 sloc) 885 Bytes
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void printArray(const int arr[], const int len) {
	for(int i = 0; i < len; i++) {
		cout << " " << arr[i];
	}
	cout << endl;
}

int main() {
	/* set */
	set<int> iset;
	iset.insert(5);
	iset.insert(9);
	iset.insert(1);
	iset.insert(8);
	iset.insert(3);

	cout << "iset contains: ";
	set<int>::iterator it;
	for(it = iset.begin(); it != iset.end(); it++)
		cout << " " << *it;
	cout << endl;

	/* binary search */
	int searchFor;
	cin >> searchFor;
	if(binary_search(iset.begin(), iset.end(), searchFor))
		cout << "Found " << searchFor << endl;
	else
		cout << "Did not find " << searchFor << endl;

	/* sort, rotate, reverse on array */
	int a[] = {5, 7, 2, 1, 4, 3, 6};
	sort(a, a + 7);
	printArray(a, 7);
	rotate(a, a + 3, a + 7);
	printArray(a, 7);
	reverse(a, a + 7);
	printArray(a, 7);

	return 0;
} 

    Contact GitHub API Training Shop Blog About 

    © 2017 GitHub, Inc. Terms Privacy Security Status Help 

