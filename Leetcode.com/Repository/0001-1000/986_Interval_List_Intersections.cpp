// https://leetcode.com/problems/interval-list-intersections/

#include <vector>
using namespace std;

// time: O(m + n)
// space: O(1)

class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    int m = firstList.size(), n = secondList.size();
    int i = 0, j = 0;

    vector<vector<int>> result;
    while (i < m and j < n) {
      int start_i = firstList[i][0], end_i = firstList[i][1];
      int start_j = secondList[j][0], end_j = secondList[j][1];
      
      if (start_i <= end_j and start_j <= end_i)
        result.push_back({ max(start_i, start_j), min(end_i, end_j) });
      
      if (end_i <= end_j)
        i++;
      else
        j++;
    }

    return result;
  }
};