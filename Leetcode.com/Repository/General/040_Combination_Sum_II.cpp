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

    for (int i = start; i < candidates.size(); i++) {
      if (i > start && candidates[i-1] == candidates[i])
        continue;
      if (candidates[i] <= target) {
        comb.emplace_back(candidates[i]);
        solve(candidates, target - candidates[i], solutions, comb, i + 1);
        comb.pop_back();
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