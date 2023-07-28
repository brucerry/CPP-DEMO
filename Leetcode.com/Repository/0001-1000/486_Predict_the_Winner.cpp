// https://leetcode.com/problems/predict-the-winner/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> memo (20, vector<int>(20, INT_MIN));
        return solve(nums, memo, 0, nums.size() - 1) >= 0;
    }

private:
    int solve(vector<int>& nums, vector<vector<int>>& memo, int l, int r) {
        if (l > r)
            return 0;

        int& res = memo[l][r];
        if (res != INT_MIN)
            return res;

        return res = max(nums[l] - solve(nums, memo, l + 1, r), nums[r] - solve(nums, memo, l, r - 1));
    }
};