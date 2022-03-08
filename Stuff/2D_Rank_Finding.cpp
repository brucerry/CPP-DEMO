#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
  int x;
  int y;
  int index;

  Point() = default;

  Point(int x, int y, int index)
    : x(x), y(y), index(index) {};  

  bool operator<(const Point& other) const {
    return x == other.x ? y < other.y : x < other.x;
  }
};

void rankFinding(vector<Point>& points, vector<int>& ranks, vector<Point>& buffer, int left, int right) {
  if (right - left <= 1) return;

  int mid = (left + right) >> 1;

  rankFinding(points, ranks, buffer, left, mid);
  rankFinding(points, ranks, buffer, mid, right);

  int leftPtr = left, leftTmp = left;
  int rightPtr = mid;
  int count = 0;

  while (leftPtr < mid || rightPtr < right) {
    if (leftPtr == mid) {
      buffer[leftTmp] = points[rightPtr];
      ranks[buffer[leftTmp].index] += count;
      rightPtr++;
      leftTmp++;
    }
    else if (rightPtr == right) {
      buffer[leftTmp] = points[leftPtr];
      leftPtr++;
      leftTmp++;
    }
    else if (points[leftPtr].y <= points[rightPtr].y) {
      buffer[leftTmp] = points[leftPtr];
      count++;
      leftPtr++;
      leftTmp++;
    }
    else {
      buffer[leftTmp] = points[rightPtr];
      ranks[buffer[leftTmp].index] += count;
      leftTmp++;
      rightPtr++;
    }
  }

  for (int i = left; i < right; i++) {
    points[i] = buffer[i];
  }
}

int main() {
  int n;
  cin >> n;

  int x, y;
  vector<Point> points;
  vector<Point> buffer (n);
  vector<int> ranks (n, 0);
  points.reserve(n);

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    points.emplace_back(x, y, i);
  }

  sort(points.begin(), points.end());

  rankFinding(points, ranks, buffer, 0, n);

  cout << ranks[0];
  for (int i = 1; i < n; i++) {
    cout << " " << ranks[i];
  }
}