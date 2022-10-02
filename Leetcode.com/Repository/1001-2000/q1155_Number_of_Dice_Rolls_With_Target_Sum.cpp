// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include <vector>
using namespace std;

// time: O(n * k * target)
// space: O(target)

class Solution {
public:
  int numRollsToTarget(int n, int k, int target) {
    vector<int> dp (target + 1), tmp (target + 1);
    dp[0] = 1;

    for (int roll = 1; roll <= n; roll++) {
      fill(tmp.begin(), tmp.end(), 0);
      for (int face = 1; face <= k; face++) {
        for (int t = face; t <= target; t++) {
          tmp[t] = (tmp[t] + dp[t - face]) % 1000000007;
        }
      }
      dp = tmp;
    }

    return dp[target];
  }
};