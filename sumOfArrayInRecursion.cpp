/*Now rewrite your function from 2.4.5 to use recursion instead of a loop. 
  The function signature should not change. Thinking about pointer arithmetic may help you. */
#include <iostream >
using namespace std;

int sum(const int *ptr, const int count) {
	if(count == 0) return 0;
	
	int result = *ptr;
	return result + sum(++ptr, count - 1);
}

int main() {
	int array[5] = {1, 2, 3, 4, 5};
	cout << sum(array, 5) << endl;

	return 0;
}
