#include <iostream >
using namespace std;

class Point {
public:
	double x;
	double y;
	Point() {
		x = 0.0;
		y = 0.0;
		cout << "Point instance created" << endl;
	}
	Point(double nx, double ny) {
		x = nx;
		y = ny;
		cout << "2-parameter constructer" << endl;
	}
	Point(Point &o) {
		x = o.x;
		y = o.y;
		cout << "custom copy constructor" << endl;
	}
};

int main() { 
	Point parray[4] = {Point(0, 1), Point(2, 1), Point(4, 1), Point(3, 3)};
	Point *parray2 = new Point[4];
	
	return 0;
}
