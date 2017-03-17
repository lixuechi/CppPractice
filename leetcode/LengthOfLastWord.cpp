/**
   Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
   return the length of last word in the string.
   If the last word does not exist, return 0.
   Note: A word is defined as a character sequence consists of non-space characters only.
    For example,
    Given s = "Hello World",
    return 5.  
 */
#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
	if(s.empty() || s == "") return 0;
	int num = 0;
	// find the first non-space character from the end of s
	string::iterator it;
	for(it = s.end() - 1; it != s.begin(); it--) {
		if(*it != ' ') break;;
	}
	for(; it != s.begin(); it--, num++){
		cout << ' ' << *it;
		if(*it == ' ' && it != s.end() - 1) return num; 
	}
	/* if write 'return num++' below, it will return num and then num += 1 */
	return (*(s.begin()) == ' ') ? num : ++num; // s.begin()
}

int main() {
	cout << lengthOfLastWord("Hello World") << endl;
	cout << lengthOfLastWord("World") << endl;
	cout << lengthOfLastWord(" ") << endl;
	cout << lengthOfLastWord(" a") << endl;
	cout << lengthOfLastWord("a ") << endl;

	return 0;
} 
