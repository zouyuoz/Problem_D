#include "Region.h"

using namespace std;

Region::Region() {}

Region::Region(Region const &r) {
	this->name = r.name;
	this->vertices = r.vertices;
}

void Region::showRegionInfo() const {
	cout << name << endl;
	for (Point v : vertices) {
		cout << "(" << v.x << ", " << v.y << ")" << endl;
	}
	cout << "----------------------" << endl;
}