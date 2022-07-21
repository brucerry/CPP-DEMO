// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int maxHeight(vector<vector<int>>& cuboids) {
    for (auto& cuboid : cuboids) {
      sort(cuboid.begin(), cuboid.end());
    }
    sort(cuboids.begin(), cuboids.end());
    
    int n = cuboids.size(), result = 0;
    vector<int> dp (n);
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = cuboids[i][2];
      for (int j = i + 1; j < n; j++) {
        if (cuboids[i][0] <= cuboids[j][0] and cuboids[i][1] <= cuboids[j][1] and cuboids[i][2] <= cuboids[j][2]) {
          dp[i] = max(dp[i], cuboids[i][2] + dp[j]);
        }
      }
      result = max(result, dp[i]);
    }
    
    return result;
  }
};