#include <iostream >
#include <stdio.h>
#include <windows.h>
using namespace std;

int main() { 
	HANDLE hOut;
	COORD pos = {0, 0};
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hOut, 0x01|0x05);

	for(int i = 0; i < 20; i++) {
		pos.X = i;
		pos.Y = i;
		SetConsoleCursorPosition(hOut, pos);
	
		printf("d%d%:HelloWorld!\n", pos.X, pos.Y);
		getchar(); // receive a char such as \n
	}
	
	return 0;
}
