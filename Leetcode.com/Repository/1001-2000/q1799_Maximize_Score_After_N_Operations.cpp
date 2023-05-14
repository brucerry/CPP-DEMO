// https://leetcode.com/problems/maximize-score-after-n-operations/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n^2 * 2^n)
// space: O(n * 2^n)

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int all = 1 << n;
        vector<vector<int>> memo (n / 2 + 1, vector<int>(all, -1));
        return solve(nums, memo, 0, 1);
    }

private:
    int solve(vector<int>& nums, vector<vector<int>>& memo, int mask, int round) {
        if (round > nums.size() / 2)
            return 0;

        int& res = memo[round][mask];
        if (res != -1)
            return res;

        res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if ((mask & (1 << i)) == 0 and (mask & (1 << j)) == 0) {
                    res = max(res, round * gcd(nums[i], nums[j]) + solve(nums, memo, mask | (1 << i) | (1 << j), round + 1));
                }
            }
        }

        return res;
    }
};