#include <iostream>
#include <string>

using namespace std;

bool isMAC48Address(string inputString) {
	int currIndex = 0;
	for (string::iterator it = inputString.begin(); it != inputString.end(); it++) {
		char c = *it;
		if ((currIndex + 1) % 3 == 0) {
			if (c != '-') {
				return false;
			}
		}
		else {
			bool cond = (c <= '9' && c >= '0') || (c <= 'F' && c >= 'A');
			if (!cond) {
				return false;
			}
		}
		currIndex++;
	}
	return currIndex == 17;
} // end function isMac48Address

int main() {
	cout << isMAC48Address("00-1B-63-84-45-E6") << endl;

	return 0;
}
