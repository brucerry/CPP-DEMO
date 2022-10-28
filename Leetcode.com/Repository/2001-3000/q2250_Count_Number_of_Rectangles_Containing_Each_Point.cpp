// https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/

#include <vector>
#include <algorithm>
using namespace std;

// r = size of rectangles
// p = size of points
// time: O(p * 100 * log(r))
// space: O(r)

class Solution {
public:
  vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
    vector<int> widthGroups[101]; // index: height, values: vector of widths
    for (const auto& rec :rectangles) {
      widthGroups[rec[1]].emplace_back(rec[0]);
    }

    for (int height = 0; height < 101; height++) {
      sort(widthGroups[height].begin(), widthGroups[height].end());
    }

    vector<int> result;
    for (const auto& pt : points) {
      int x = pt[0], y = pt[1], count = 0;
      for (int height = y; height < 101; height++) {
        auto it = lower_bound(widthGroups[height].begin(), widthGroups[height].end(), x);
        count += widthGroups[height].end() - it;
      }
      result.emplace_back(count);
    }

    return result;
  }
};