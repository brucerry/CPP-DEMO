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

void rankFinding(vector<Point>& points, vector<int>& ranks, vector<Point>& tmp, int left, int right) {
  if (right - left == 1) return;

  int mid = left + ((right - left) >> 1);

  rankFinding(points, ranks, tmp, left, mid);
  rankFinding(points, ranks, tmp, mid, right);

  int leftPtr = left;
  int rightPtr = mid;
  int fullPtr = left;
  int count = 0;

  // supposed that both left & right subarray were sorted in ascending order separately

  // points is sorted in ascending order by x then y
  // tmp is a buffer for storing points in ascending order by comparing y <= other.y

  while (leftPtr < mid || rightPtr < right) {
    if (leftPtr == mid) {
      tmp[fullPtr] = points[rightPtr++];
      ranks[tmp[fullPtr].index] += count;
    }
    else if (rightPtr == right) {
      tmp[fullPtr] = points[leftPtr++];
    }
    else if (points[leftPtr].y <= points[rightPtr].y) {
      tmp[fullPtr] = points[leftPtr++];
      count++;
    }
    else {
      tmp[fullPtr] = points[rightPtr++];
      ranks[tmp[fullPtr].index] += count;
    }
    fullPtr++;
  }

  for (int i = left; i < right; i++) {
    points[i] = tmp[i];
  }
}

int main() {
  int n;
  cin >> n;

  int x, y;
  vector<Point> points;
  vector<Point> tmp (n);
  vector<int> ranks (n, 0);
  points.reserve(n);

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    points.emplace_back(x, y, i);
  }

  sort(points.begin(), points.end()); // sort in ascending by x then y

  rankFinding(points, ranks, tmp, 0, n);

  cout << ranks[0];
  for (int i = 1; i < n; i++) {
    cout << " " << ranks[i];
  }
}