/*  
	Functor.
 */
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Abs {
public:
	int operator() (int num) const;
	Abs();
	void setIsOpponent(bool isOpponent);

private:
	bool isOpponent;
};

int Abs::operator() (int num) const {
	int res;
	if(!isOpponent) {
		res = num > 0 ? num : -num;
	} else {
		res = num > 0 ? -num : num;
	}
	return res;
}

Abs::Abs() {
	isOpponent = false;
}

void Abs::setIsOpponent(bool aIsOpponent) {
	isOpponent = aIsOpponent;
}

int main() {
	Abs myAbs;
	myAbs.setIsOpponent(true);
	int value = myAbs(-23);

	return 0;
}
