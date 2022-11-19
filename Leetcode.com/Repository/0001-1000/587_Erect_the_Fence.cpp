// https://leetcode.com/problems/erect-the-fence/

#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  vector<vector<int>> outerTrees(vector<vector<int>>& points) {
    int n = points.size();
    sort(points.begin(), points.end());
    
    vector<int> lower, upper; // store indices
    bitset<3000> l, u;
    for (int i = 0; i < n; i++) {
      while (lower.size() >= 2 and cmp(points[lower[lower.size()-2]], points[lower.back()], points[i]) < 0) {
        l[lower.back()] = 0;
        lower.pop_back();
      }
      while (upper.size() >= 2 and cmp(points[upper[upper.size()-2]], points[upper.back()], points[i]) > 0) {
        u[upper.back()] = 0;
        upper.pop_back();
      }
      lower.emplace_back(i);
      upper.emplace_back(i);
      l[i] = u[i] = 1;
    }

    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
      if (l[i] or u[i])
        res.emplace_back(points[i]);
    }
    return res;
  }

private:
  int cmp(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
    int x1 = p1[0], y1 = p1[1];
    int x2 = p2[0], y2 = p2[1];
    int x3 = p3[0], y3 = p3[1];
    return (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);
  }
};