#include <stdio.h>
using namespace std;

int main() {
	//int i = 10;
	volatile int i = 10;
	int a = i;

	printf("i = %d", a);

	__asm {
		mov dword ptr [ebp - 4], 20h
	}

	int b = i;
	printf("i = %d", b);

	return 0;
}
