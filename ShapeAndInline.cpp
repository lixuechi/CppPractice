/**
   
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int M_PI = 3.14;

class Shape {
public:
	virtual double area() const = 0;
	virtual ~Shape() {}
};

class Circle : public Shape {
	double _radius;
public:
	Circle(double theRadius) : _radius(theRadius) {}
	~Circle() {}
	/* will not write what inline means, you have to understand it from the lowest level LOL */
	inline double radius() const { return _radius; }
	double area() const { return _radius * _radius * M_PI; }
};

int main() {

	return 0;
} 
