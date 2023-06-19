// https://leetcode.com/problems/combination-sum-iii/

#include <vector>
using namespace std;

// time: O(9 * 2^9)
// space: O(k)

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> state;
        solve(k, n, res, state, 0, 1);
        return res;
    }

private:
    void solve(int k, int target, vector<vector<int>>& res, vector<int>& state, int mask, int start) {
        if (state.size() == k and target == 0) {
            res.emplace_back(state);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if ((mask & (1 << i)) == 0 and target >= i) {
                state.emplace_back(i);
                solve(k, target - i, res, state, mask | (1 << i), i + 1);
                state.pop_back();
            }
        }
    }
};