/*  Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
    find the one that is missing from the array.
    For example, Given nums = [0, 1, 3] return 2.
	Note: Your algorithm should run in linear runtime complexity. 
	      Could you implement it using only constant extra space complexity?*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	if(nums[0] != 0) return 0;
	vector<int>::iterator it;
	for(it = nums.begin(); it != nums.end() - 1; it++) 
		if(*(it + 1) - *it > 1) return *it + 1;
	return *it + 1;
}

int main() {
	int arr[] = {0, 1, 3};
	vector<int> ivec(begin(arr), end(arr));
	cout << missingNumber(ivec) << endl;

	vector<int> jvec; jvec.push_back(0);
	cout << missingNumber(jvec) << endl;

	vector<int> kvec; kvec.push_back(1); kvec.push_back(0);
	cout << missingNumber(kvec) << endl;

	return 0;
}
