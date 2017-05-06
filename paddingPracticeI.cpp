/*  */
#include <iostream>
using namespace std;

class B {
private:
	bool m_bTemp;
	int m_nTemp;
	bool m_bTemp2;
};

class C {
private:
	int m_nTemp;
	bool m_bTemp;
	bool m_bTemp2;
};

struct aStruct {
	char cValue;
	int iValue;
};

/* byte alignment is determined at compile time, it won't change after the determination */

/* '#pragma pack(n)'- the compiler will align by n bytes
   '#pragma pack()'- the compiler will cancel custom byte alignment */

#pragma pack(8)
struct TestStruct4 {
	char a;
	long b;
};
/* memory allocation of TestStruct4 
a    b
1*** 1111
*/

struct TestStruct5 {
	char c;
	TestStruct4 d;
	long long e;
};

/* memory allocation of TestStruct5
c    d.a  d.b       e
1*** 1*** 1111 **** 11111111
*/

int main() {
	cout << sizeof(B) << endl; // output 12
	cout << sizeof(C) << endl; // output 8

	cout << sizeof(TestStruct4) << endl; // output 8
	cout << sizeof(TestStruct5) << endl; // output 24

	char *sz = "0123456789";
	int *p = (int *)sz;
	cout << hex << *++p << endl; // output 37363534
	/* 
	memory address: 0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07 0x08 0x09
	value         :    0    1    2    3    4    5    6    7    8    9
	value         :   48   49   50   51   52   53   54   55   56   57
	hex           : 0x30 0x31 0x32 0x33 0x34 0x35 0x36 0x37 0x38 0x39
	*/

	system("pause");

	return 0;
}
