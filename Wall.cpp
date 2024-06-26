#include "Wall.h"

Wall::Wall(bool IsVertical, double Fixed, double Range[2], string Name) : isVertical(IsVertical), fixedCoord(Fixed){
	rangeCoord[0] = Range[0];
	rangeCoord[1] = Range[1];
	this->name = Name;
}


Wall::Wall(bool IsVertical, double Fixed, double Range1, double Range2, string name){
	isVertical = IsVertical;
	fixedCoord = Fixed;
	rangeCoord[0] = Range1;
	rangeCoord[1] = Range2;
	this->name = name;
}

Point inOrder(double a, double b){
	double small = min(a, b);
	double big = max(a, b);
	return Point(small, big);
}

void Wall::getBlockVertices(Block const &b) {
  	if (b.is_feedthroughable) return;
	for (int i = 0; i < b.vertices.size(); i++) {
		double x1 = b.vertices[i].x;
		double x2 = b.vertices[(i + 1) % b.vertices.size()].x;
		double y1 = b.vertices[i].y;
		double y2 = b.vertices[(i + 1) % b.vertices.size()].y;
		if (x1 == x2) {
			// then it should be the vertical wall
			double y[2] = {inOrder(y1, y2).x, inOrder(y1, y2).y};
			allWalls.push_back(Wall(1, x1, y, b.name));
		} else if (y1 == y2) {
			// then it should be the horizontal wall
			double x[2] = {inOrder(x1, x2).x, inOrder(x1, x2).y};
			allWalls.push_back(Wall(0, y1, x, b.name));
		}
	}
}

bool compare(const Wall &a, const Wall &b) {
  return a.fixedCoord < b.fixedCoord;
}
void Wall::rearrangement() { sort(allWalls.begin(), allWalls.end(), compare); }

bool Wall::inRange(double const &value) const {
  return rangeCoord[0] <= value && rangeCoord[1] >= value;
}