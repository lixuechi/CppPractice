/* Transpose a matrix with array-subscript notation and pointer-offset notation */
#include <iostream >
using namespace std;

void printArray(int *ptr, int num) {
	char *str = ", ";

	for(int i = 0; i < num; i++, ptr++) {
		cout << *ptr; 
		if(i != num - 1) {
			cout << *str; 
		}
	}
	cout << endl;
}

void reverse(int *ptr, int len) {
	char *str = ", ";
	int *revPtr = ptr;

	int c = len / 2;
	for(int i = 0; i < c; i++, revPtr++) {
		int temp = *revPtr;
		*revPtr = *(revPtr + len - 1 - i - i);
		*(revPtr + len - 1 - i - i) = temp;
	}

	for(int i = 0; i < len; i++, ptr++) {
		cout << *ptr; 
		if(i != len - 1) {
			cout << *str; 
		}
	}
	cout << endl;
}

const int WIDTH = 2;
const int LENGTH = 3;
/*
void transpose(const int input[][LENGTH], int output[][WIDTH]) {
	for(int i = 0; i < LENGTH; i++) {
		for(int j = 0; j < WIDTH; j++) {
			output[i][j] = input[j][i];
			//cout << "output[" << i << "][" << j << "]" << output[i][j] << endl;
		}
	}
}
*/
int* transpose(const int input[][LENGTH]) {
	int output[][WIDTH] = {{0, 0}, {0, 0}, {0, 0}};

	for(int i = 0; i < LENGTH; i++) {
		for(int j = 0; j < WIDTH; j++) {
			//output[i][j] = input[j][i];
			*(*(output + i) + j) = *(*(input + j) + i);
			cout << "output[" << i << "][" << j << "]" << output[i][j] << endl;
		}
	}

	return *output;
}

int main() {
	int array[] = {1, 2, 3, 4, 5};
	//printArray(array, 5);
	//reverse(array, 5);

	int matrixA[][WIDTH] = {{0, 0}, {0, 0}, {0, 0}};
	int matrixB[][LENGTH] = {{1, 3, 5}, {2, 4, 6}};
	transpose(matrixB);

	//cout << **(matrixB + 1) << endl; // 2
	//cout << *(*matrixB + 1) << endl; // 3

	for(int a = 0; a < LENGTH; a++) {
		for(int b = 0; b < WIDTH; b++) {
			//cout << "matrixA[" << a << "][" << b << "]" << matrixA[a][b] << endl;
			//cout << "matrixA[" << a << "][" << b << "]" << matrixA[a][b] << endl;
		}
	}

	return 0;
}
