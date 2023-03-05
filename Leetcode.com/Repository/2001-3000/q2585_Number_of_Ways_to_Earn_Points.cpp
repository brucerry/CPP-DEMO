// https://leetcode.com/problems/number-of-ways-to-earn-points/

// Limited Coin Change

#include <vector>
using namespace std;

// count = types[i][0]
// mark = types[i][1]
// time: O(target * count * mark)
// space: O(target)

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int dp[1001] = { 1 }, mod = 1e9 + 7;
        for (const auto& type : types) {
            int count = type[0];
            int mark = type[1];
            for (int t = target; t >= 0; t--) {
                for (int m = mark; m <= mark * count; m += mark) {
                    if (t >= m) {
                        dp[t] = (dp[t] + dp[t - m]) % mod;
                    }
                }
            }
        }
        return dp[target];
    }
};