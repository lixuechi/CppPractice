/* In this section you will write a program that turns a given English word into Pig Latin. 
   Pig Latin is a language game of alterations played in English. To form the Pig Latin version 
   of an English word, the onset of the first consonant is transposed to the end of the word 
   an an ay is affixed. Here are the rules:
	1. In words that begin with consonant sounds, the initial consonant (if the word starts
	   with ‘q’, then treat ‘qu’ as the initial consonant) is moved to the end of the word, and
	   an “ay” is added. For example:
       • beast : east-bay
       • dough : ough-day
       • happy : appy-hay
       • question : estion-quay
    2. In words that begin with vowel sounds, the syllable “way” is simply added to the end
       of the word. */
#include <string>
#include <iostream>
using namespace std;

const char* VOWELS = "aeiou";

string pigLatinify(string word) {
	char start = word.at(0);
	bool isStartVowel = false;
	string newStr = "";

	for(int i = 0; i < 5; i++) {
		if(*(VOWELS + i) == start) {
			isStartVowel = true;
		}
	}

	string consonant = start + "";
	if(!isStartVowel) {
		switch(start) {
		case 'b':
		case 'f':
		case 'g':
		case 'h':
		case 'j':
		case 'l':
		case 'm':
		case 'n':
		case 'r':
		case 'v':
		case 'x':
		case 'y':
		case 'z':
			consonant = start;
			newStr = word.substr(1) + "-" + consonant + "ay";
			break;
		case 'c':
		case 'p':
		case 's':
			if(word.at(1) == 'h') {
				consonant = start + 'h';
				newStr = word.substr(2) + "-" + consonant + "ay";
			} else {
				newStr = word.substr(1) + "-" + consonant + "ay";
			}
			break;
		case 'd':
			if(word.at(1) == 'r') { 
				consonant = start + 'r';
				newStr = word.substr(2) + "-" + consonant + "ay";
			} else {
				newStr = word.substr(1) + "-" + consonant + "ay";
			}
			break;
		case 'k':
			if(word.at(1) == 'n') {
				consonant = start + 'n';
				newStr = word.substr(2) + "-" + consonant + "ay";
			} else {
				newStr = word.substr(1) + "-" + consonant + "ay";
			}
			break;
		case 'q':
			if(word.at(1) == 'u') {
				consonant = start + 'u';
				newStr = word.substr(2) + "-" + consonant + "ay";
			} else {
				newStr = word.substr(1) + "-" + consonant + "ay";
			}
			break;
		case 't':
		case 'w':
			if(word.at(1) == 'h') {
				consonant = start + 'h';
				newStr = word.substr(2) + "-" + consonant + "ay";
			} else if(word.at(1) == 'r') { 
				consonant = start + 'r';
				newStr = word.substr(2) + "-" + consonant + "ay";
			} else {
				newStr = word.substr(1) + "-" + consonant + "ay";
			}
			break;
		}
	} else {
		newStr = word + "-way";
	}

	return newStr;
}

int main() {
	cout << pigLatinify("beast") << endl;
	cout << pigLatinify("dough") << endl;
	cout << pigLatinify("happy") << endl;
	cout << pigLatinify("question") << endl;
	cout << pigLatinify("apple") << endl;
	cout << pigLatinify("ice") << endl;

	return 0;
}
