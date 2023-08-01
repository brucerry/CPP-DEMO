// https://leetcode.com/problems/combinations/

#include <vector>
using namespace std;

// time: O(n choose k)
// space: O(k)

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> state;
        solve(n, k, res, state, 1);
        return res;
    }

private:
    void solve(int n, int k, vector<vector<int>>& res, vector<int>& state, int start) {
        if (state.size() == k) {
            res.emplace_back(state);
            return;
        }

        for (int i = start; i <= n; i++) {
            state.emplace_back(i);
            solve(n, k, res, state, i + 1);
            state.pop_back();
        }
    }
};