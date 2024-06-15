#include "Region.h"

using namespace std;

Region::Region() {}

Region::Region(Region const &r) {
  this->name = r.name;
  this->vertices = r.vertices;
}

void Region::expandVertices() {
  // (x0 y1) [x1 y1]
  // [x0 y0] (x1 y0)
  // clockwise
  pair<double, double> tempVertice(vertices[0].first, vertices[1].second);
  vertices.insert(vertices.begin() + 1, tempVertice);
  tempVertice = make_pair(vertices[2].first, vertices[0].second);
  vertices.push_back(tempVertice);
}

void Region::showRegionInfo() {
  cout << name << endl;
  for (pair<double, double> v : vertices) {
    cout << "(" << v.first << ", " << v.second << ")" << endl;
  }
  cout << "----------------------" << endl;
}

void Region::ParserAllRegions(int const &testCase) {
  // Open chip_top.def to get
  // regionName, vertices
  ifstream file("case" + to_string(testCase) + "_def/chip_top.def");
  string line;
  string startWith = "- REGION_";
  regex getRegionName(R"(REGION_\d+)");
  regex getVertices(R"(\(\s*([\d.]+)\s+([\d.]+)\s*\))");
  smatch m;
  while (getline(file, line)) {
    Region tempRegion;
    if (line.find(startWith) == 0) {
      // regionName
      if (regex_search(line, m, getRegionName)) {
        tempRegion.name = m.str();
      }

      // vertices
      sregex_iterator iter(line.begin(), line.end(), getVertices);
      sregex_iterator end;
      while (iter != end) {
        smatch match = *iter;
        double x = stod(match[1].str());
        double y = stod(match[2].str());
        tempRegion.vertices.push_back(make_pair(x, y));
        ++iter;
      }
      tempRegion.expandVertices();
      this->allRegions.push_back(tempRegion);
    }
  }
}