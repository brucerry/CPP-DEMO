// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minCost(string& colors, vector<int>& neededTime) {
    int n = colors.length(), cost = 0;
    for (int i = 1; i < n; i++) {
      if (colors[i-1] == colors[i]) {
        cost += min(neededTime[i-1], neededTime[i]);
        neededTime[i] = max(neededTime[i], neededTime[i-1]);
      }
    }
    return cost;
  }
};