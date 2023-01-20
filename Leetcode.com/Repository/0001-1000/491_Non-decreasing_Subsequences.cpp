// https://leetcode.com/problems/non-decreasing-subsequences/

#include <vector>
#include <set>
using namespace std;

// time: O(n * 2^n)
// space: O(n)

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> state;
        solve(nums, res, state, 0);
        return vector(res.begin(), res.end());
    }

private:
    void solve(vector<int>& nums, set<vector<int>>& res, vector<int>& state, int start) {
        if (state.size() >= 2)
            res.emplace(state);

        for (int i = start; i < nums.size(); i++) {
            if (state.size() == 0 or nums[i] >= state.back()) {
                state.emplace_back(nums[i]);
                solve(nums, res, state, i + 1);
                state.pop_back();
            }
        }
    }
};