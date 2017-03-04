/* '.' Matches any single character.
   '*' Matches zero or more of the preceding element.
   The matching should cover the entire input string (not partial).
   The function prototype should be: bool isMatch(const char *s, const char *p)
   Some examples:
	isMatch("aa","a") → false
	isMatch("aa","aa") → true
	isMatch("aaa","aa") → false
	isMatch("aa", "a*") → true
	isMatch("aa", ".*") → true
	isMatch("ab", ".*") → true
	isMatch("aab", "c*a*b") → true */
#include <iostream>
using namespace std;

bool isMatch(const char *s, const char *p) {
	// find len of s and p
	int lenS = strlen(s);
	int lenP = strlen(p);
	if(lenS > lenP) return false;

	bool isGoodSoFar = false;

	// lenP >= lenS
	for(int i = 0; i < lenS; i++) {
		for(int j = 0; j < lenP; j++) {
			char currS = s[i];
			char currP = p[j];

			if(currS == currP || currP == '.'){
				isGoodSoFar = true;
			}
			
			if(j >= 1) {
				if(currP == '*' && (p[j - 1] == s[i] || p[j - 1] == '.')) {
					isGoodSoFar = true;
				}
			}
		}
		isGoodSoFar = false;
	}

	return true;
}

int main() {
	/*
	char *sStr = "aab";
	char *pStr = "c*a*b";
	*/
	/*
	char *sStr = "aaa";
	char *pStr = "aa";
	*/
	char *sStr = "ab";
	char *pStr = ".*";
	cout << (isMatch(sStr, pStr) ? "Yes" : "No");



	return 0;
} 