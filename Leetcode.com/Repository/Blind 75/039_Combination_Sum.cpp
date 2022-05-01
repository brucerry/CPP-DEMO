// https://leetcode.com/problems/combination-sum/

#include <vector>
using namespace std;

// t = target
// time: O(2^t)
// space: O(t)

class Solution {
private:
  void solve(vector<int>& candidates, int target, vector<vector<int>>& solutions, vector<int>& comb, int start) {
    if (target == 0)
      solutions.emplace_back(comb);

    if (start == candidates.size() || target == 0)
      return;

    for (int i = start; i < candidates.size(); i++) {
      if (candidates[i] <= target) {
        comb.emplace_back(candidates[i]);
        solve(candidates, target - candidates[i], solutions, comb, i);
        comb.pop_back();
      }
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> solutions;
    vector<int> comb;
    solve(candidates, target, solutions, comb, 0);
    return solutions;
  }
};