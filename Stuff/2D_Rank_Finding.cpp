#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
  int x;
  int y;
  int index;

  Point(int x, int y, int index)
    : x(x), y(y), index(index) {};  

  bool operator<(const Point& other) const {
    return x == other.x ? y < other.y : x < other.x;
  }
};

int main() {
  int n;
  cin >> n;

  int x, y;
  vector<Point> points;
  vector<int> result (n);
  result[0] = 0;
  points.reserve(n);

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    points.emplace_back(x, y, i);
  }

  sort(points.begin(), points.end());

  
}