#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

bool x_comparator(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
  auto& [ ax, ay, ai ] = a;
  auto& [ bx, by, bi ] = b;

  if (ax == bx)
    return ay < by;
  
  return ax < bx;
}

bool y_comparator(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
  auto& [ ax, ay, ai ] = a;
  auto& [ bx, by, bi ] = b;

  if (ay == by)
    return ax < bx;
  
  return ay < by;
}

int main() {
  // const vector<pair<int, int>> points {
  //   {3, 1},
  //   {4, 1},
  //   {5, 9},
  //   {2, 6},
  //   {5, 3},
  //   {5, 8},
  //   {9, 7}
  // };


  
  int n;
  cin >> n;

  vector<int> ranks (n, INT_MAX);
  vector<tuple<int, int, int>> points;
  points.reserve(n);

  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    points.emplace_back(x, y, i);
  }

  vector<tuple<int, int, int>> sortPointsX (points); // copy points
  vector<tuple<int, int, int>> sortPointsY (points); // copy points

  sort(sortPointsX.begin(), sortPointsX.end(), x_comparator); // sort by x then y
  sort(sortPointsY.begin(), sortPointsY.end(), y_comparator); // sort by y then x
  
  for (int i = 0; i < n; i++) {
    auto& [ x, y, originalIndex ] = sortPointsX[i];
    ranks[originalIndex] = min(ranks[originalIndex], i);
  }

  for (int i = 0; i < n; i++) {
    auto& [ x, y, originalIndex ] = sortPointsY[i];
    ranks[originalIndex] = min(ranks[originalIndex], i);
  }

  for (int& rank : ranks) {
    cout << rank << ' ';
  }
}