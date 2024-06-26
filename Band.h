#ifndef BAND_H_INCLUDED
#define BAND_H_INCLUDED

#include <vector>
#include "AllZone.h"

using namespace std;

class Band {
public: 
	Band(){}
	Band(bool, bool, double, double, double, double, Band*);
	bool containTerminal;
	Band *parent = nullptr;
	int level = 0;
	bool direction_isX;
	bool toExtend_isX; // oppsite of direction_isX (!direction_isX)

	double minEnd; // means direction hitWall
	double maxEnd; // means direction hitwall

	double minEdge; // means extend detectWall
	double maxEdge; // means extend detectWall

	vector<Band> toExtendPaths;

	// member fuctions
	Band extendedBand(double dx, double dy, int lv);
	bool detectWall(Wall const allWall) const;
};

#endif // BAND_H_INCLUDED