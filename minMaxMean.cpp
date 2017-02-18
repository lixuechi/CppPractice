/* Given a list of N integers, find its mean (as a double), maximum value, minimum value,
   and range. Your program will first ask for N, the number of integers in the list, which the 
   user will input. Then the user will input N more numbers.
   Here is a sample input sequence:
   3 <-- N
   2
   1
   3
   Three numbers are given: 2, 1, 3. The output should be as follows:
   Mean: 2
   Max: 3
   Min: 1
   Range: 2 */
#include <iostream>
using namespace std;

int main() {
	cout << "the length of the list is: ";
	int len;
	cin >> len;

	int array[100];
	cout << "\ninput the items of the list: " << endl;
	for(int i = 0; i < len; i++) {
		cin >> array[i];
	}

	bool bArray[100];
	for(int j = 0; j < len; j++) {
		bArray[j] = false;
	}

	int min;
	int max;
	double mean;
	int range;
	int sortedArray[100];
	int s = 0;
	for(int k = 0; k < len;) {
		int tempMinIndex;
		int tempMin;
		if(!bArray[k]) {
			tempMin = array[k];
			tempMinIndex = k;
			for(int l = 0; l < len; l++) {
				if(!bArray[l] && l != k) {
					if(tempMin > array[l]) {
						tempMin = array[l];
						tempMinIndex = l;
					}
				}
			}
			bArray[tempMinIndex] = true;
			sortedArray[s++] = tempMin;
		} else {
			k++;
		}
	}
	for(int x = 0; x < len; x++) {
		if(!bArray[x]) {
			sortedArray[len - 1] = array[x];
		}
	}

	min = sortedArray[0];
	max = sortedArray[len - 1];

	if(len % 2 == 0) {
		mean = (sortedArray[len / 2 - 1] + sortedArray[len / 2]) / 2.0;
	} else {
		mean = sortedArray[len / 2];
	}

	range = max - min;

	cout << "\nMean: " << mean << "\nMax: " << max << "\nMin: " << min << "\nRange: " << range << endl;
}
