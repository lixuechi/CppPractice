/* There are two sorted arrays nums1 and nums2 of size m and n respectively. 
   Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
   Example 1:
    nums1 = [1, 3]
	nums2 = [2]
    The median is 2.0
   Example 2:
    nums1 = [1, 2]
	nums2 = [3, 4]
    The median is (2 + 3)/2 = 2.5 */
#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	int len3 = len1 + len2;

	vector<int> num3;

	for(int i = 0; i < len1; i++) {
		for(int j = 0; j < len2; j++) {
			if(num2[j] < num1[i]) {
				num3.push_back(num2[j]);
			}
		}
		num3.push_back(num1[i]);
	}

	// output num3
	for(int i = 0; i < len3; i++) {
		cout << num3[i] << endl;
	}

	int median = 0;
	if(len3 % 2 == 0) {
		median = (num3[len3 / 2] + num3[len3 / 2 + 1]) / 2.0;
	} else {
		median = num3[len3 / 2];
	}

	return median;
}

int main() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(2);

	cout << "Median = " << findMedianSortedArrays(v1, v2);

	return 0;
} 