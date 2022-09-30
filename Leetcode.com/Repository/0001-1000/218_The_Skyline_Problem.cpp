// https://leetcode.com/problems/the-skyline-problem/

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> edges, result;
    for (const auto& b : buildings) {
      edges.push_back({ b[0], -b[2] });
      edges.push_back({ b[1], b[2] });
    }
    sort(edges.begin(), edges.end());

    multiset<int> leftendHeights = { 0 };
    int top = 0;
    for (const auto& edge : edges) {
      int x = edge[0], height = edge[1];
      if (height < 0)
        leftendHeights.insert(-height);
      else
        leftendHeights.erase(leftendHeights.find(height));

      if (*leftendHeights.rbegin() != top) {
        top = *leftendHeights.rbegin();
        result.push_back({ x, top });
      }
    }

    return result;
  }
};