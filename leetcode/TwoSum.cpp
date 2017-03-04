/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
   You may assume that each input would have exactly one solution, and you may not use the same element twice.
   Example:
    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1]. */
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	int len = nums.size();
	vector<int> result;
	
	for(int i = 0; i < len; i++) {

		for(int j = i + 1; j < len; j++) {
			if(nums.at(i) + nums.at(j) == target) {
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}

	return result;
}

int main() {
	vector<int> tomYum;
	tomYum.push_back(2);
	tomYum.push_back(7);
	tomYum.push_back(11);
	tomYum.push_back(15);
	int n = 9;

	vector<int> r;
	r = twoSum(tomYum, n);
	for(int i = 0; i < r.size(); i++) {
		cout << r.at(i) << endl;
	}

	return 0;
} 
