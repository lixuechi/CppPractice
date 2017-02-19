class Point {
private:
	int x, y;
public:
	Point(int u = 0, int v = 0):x(u), y(v) {}
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(const int new_x) { x = new_x; }
	void setY(const int new_y) { y = new_y; }
};
