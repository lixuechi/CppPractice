/**
   Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
   You may assume the integer do not contain any leading zero, except the number 0 itself.
   The digits are stored such that the most significant digit is at the head of the list.
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* my solution */
vector<int> plusOne(vector<int>& digits) {
	vector<int> res;
	if(digits.empty()) return res;
	bool isCarry = true;
	for(int i = digits.size() - 1; i >= 0; i--) {
		int insertNum = isCarry ? (digits[i] + 1) % 10 : digits[i];
		res.insert(res.begin(), insertNum);
		isCarry = (isCarry && digits[i] == 9) ? true : false;
		if(i == 0 && isCarry) res.insert(res.begin(), 1);
	}

	// test
	for(int j = 0; j < res.size(); j++) {
		cout << res[j] << endl;
	}

	return res;
}

int main() {
	vector<int> d;
	d.push_back(1); d.push_back(1); d.push_back(9);
	plusOne(d);
	return 0;
} 
