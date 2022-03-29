// https://leetcode.com/problems/combination-sum-ii/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(2^n)
// space: O(n)

class Solution {
private:
  void solve(vector<int>& candidates, int target, vector<vector<int>>& solutions, vector<int>& comb, int start) {
    if (target == 0) {
      solutions.emplace_back(comb);
      return;
    }

    int prev = -1;

    for (int i = start; i < candidates.size(); i++) {
      if (candidates[i] <= target && candidates[i] != prev) {
        comb.emplace_back(candidates[i]);
        solve(candidates, target - candidates[i], solutions, comb, i + 1);
        comb.pop_back();
        prev = candidates[i];
      }
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> solutions;
    vector<int> comb;
    solve(candidates, target, solutions, comb, 0);
    return solutions;
  }
};