// roman_to_int.cpp  

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

const int I = 1;
const int X = 10;
const int C = 100;
const int M = 1000;
const int V = 5;
const int L = 50;
const int D = 500;
const int ERR = -1;

int getValue(char c);

/// <summary>
/// Converts a roman numeral to an integer
/// </summary>
/// <remarks>  
/// Compares each char in the roman numeral with its following char with the below principles:
/// 1. if the two chars are the same, add them up;
/// 2. if the value of the prior char is bigger than the following char, add them up;
/// 3. if the value of the prior char is smaller than the following char, let the following one minus the other.
/// </remarks>
/// <param name="s">
/// Roman numeral to be converted
/// </param>  
/// <exception cref="std::exception">
/// Thrown when the roman numeral input is invalid
/// </exception>
/// <returns>
/// the result integer after conversion
/// </returns> 
int romanToInt(string s) {
	int i = ERR;
	try{
		i = getValue(*(s.end() - 1)); 
		int currCharVal = i;

		if(s.length() == 1) return i;
		
		for(string::iterator it = s.end() - 2; it != s.begin(); it--) {
			int itVal = getValue(*it);
			i += (itVal >= currCharVal) ? itVal : -itVal; 
			currCharVal = itVal;
		}
	
		int firstCharVal = getValue(*(s.begin()));
		i += (firstCharVal >= currCharVal) ? firstCharVal : -firstCharVal;
	} catch (std::exception &ex) {
		cout << "Caught exception: " << ex.what() << endl;
	}
	return i;
}

/// <summary>
/// Gets the corresponding integer value of a roman numeral character
/// </summary>
/// <param name="c">
/// Roman numeral character
/// </param>  
/// <exception cref="std::exception">
/// Thrown when the roman numeral character is invalid
/// </exception>
/// <returns>
/// the result integer value
/// </returns> 
int getValue(char c) {
	switch(c) {
	case 'I':
		return I;
	case 'X':
		return X;
	case 'C':
		return C;
	case 'M':
		return M;
	case 'V':
		return V;
	case 'L':
		return L;
	case 'D':
		return D;
	default:
		throw std::exception("Invalid roman numeral.");
		return ERR;
	}
}

/// <example> This sample shows how to call the romanToInt method.  
/// <code>
int main() {
	cout << "W = " << romanToInt("W") << endl; // exception
	cout << "C = " << romanToInt("C") << endl; // 100
	cout << "III = " << romanToInt("III") << endl; // 3
	cout << "IV = " << romanToInt("IV") << endl; // 4
	cout << "VI = " << romanToInt("VI") << endl; // 6
	cout << "XIX = " << romanToInt("XIX") << endl; // 19
	cout << "XX = " << romanToInt("XX") << endl; // 20
	cout << "XLV = " << romanToInt("XLV") << endl; // 45
	cout << "MCMLXXX = " << romanToInt("MCMLXXX") << endl; // 1980
	cout << "CMXCIX = " << romanToInt("CMXCIX") << endl; // 999

	return 0;
}
/// </code>
/// </example>
