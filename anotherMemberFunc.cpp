#include <iostream >
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int u, int v):x(u), y(v) {}
	int getX() const { return x; }
	int getY() { return y; }
	/* x, y cannot be modified thru a const object
	void doubleVal() const {
		x = x * 2;
		y = y * 2;
	}
	*/
};

int main() { 
	const Point myPoint(5, 3);
	//myPoint.doubleVal();
	cout << myPoint.getX() << endl;

	return 0;
}
