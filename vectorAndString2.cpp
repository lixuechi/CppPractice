/**
   
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> intArray;
	int count = 0;
	while(count < 9) {
		intArray.push_back(count);
		count++;
	}
	int secondItem = intArray[count];

	vector<string> stringList;
	stringList.push_back("C99");
	stringList.push_back("C++03");
	stringList.push_back("C++11");

	return 0;
} 
