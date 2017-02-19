#include "geometry.h"

class PointArray {
private:
	Point *pArray;
	int length;

	void resize(int n) {
		length = n;
	}
public:
	PointArray() { length = 0; }

	PointArray(const Point points[], const int size) {
		length = size;

		for(int i = 0; i < length; i++) {
			*(pArray + i) = points[i];
		}
	}

	PointArray(const PointArray& pv) {
		length = pv.getSize();
		pArray = pv.getPArray();
	}

	~PointArray() {}

	Point *getPArray() const {
		return pArray;
	}

	/* Add a Point to the end of the array */
	void push_back(const Point &p) {
		*(pArray + length) = p;
		length++;
	}

	/* Insert a Point at some arbitrary position (subscript) of the array, 
	   shifting the elements past position to the right. */
	void insert(const int position, const Point &p) {
		for(int i = length - 1; i >= position; i--) {
			*(pArray + i + 1) = *(pArray + i);
		}
		*(pArray + position) = p; 
		length++;
	}

	/* Remove the Point at some arbitrary position (subscript) of the array, 
	   shifting the remaining elements to the left. */
	void remove(const int pos) {
		for(int i = pos; i < length - 1; i++) {
			*(pArray + i) = *(pArray + i + 1);
		}
		length--;
	}

	/* Get the size of the array */
	const int getSize() const {
		return length;
	}

	/* Remove everything from the array and sets its size to 0 */
	void clear() {
		length = 0;
	}

	/* Get a pointer to the element at some arbitrary position in the array, 
	   where positions start at 0 as with arrays. */
	Point get(const int position) {
		if(position < length) {
			return *(pArray + position);
		}
	}

	const Point get(const int position) const {
		if(position < length) {
			return *(pArray + position);
		}
	}
};
