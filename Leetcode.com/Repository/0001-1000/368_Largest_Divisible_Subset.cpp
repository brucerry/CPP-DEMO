// https://leetcode.com/problems/largest-divisible-subset/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp (n);
        for (int i = 0; i < n; i++) {
            dp[i] = { nums[i] };
        }
        vector<int> res;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0 and dp[i].size() < dp[j].size() + 1) {
                    dp[i] = { nums[i] };
                    dp[i].insert(dp[i].end(), dp[j].begin(), dp[j].end());
                }
            }
            if (dp[i].size() > res.size())
                res = dp[i];
        }
        return res;
    }
};