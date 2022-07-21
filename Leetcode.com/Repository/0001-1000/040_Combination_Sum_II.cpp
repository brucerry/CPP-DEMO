// https://leetcode.com/problems/combination-sum-ii/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * 2^n)
// space: O(n)

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    
    vector<vector<int>> solution;
    vector<int> comb;
    solve(candidates, target, solution, comb, 0);
    return solution;
  }
  
private:
  void solve(vector<int>& candidates, int target, vector<vector<int>>& solution, vector<int>& comb, int start) {
    if (target == 0) {
      solution.emplace_back(comb);
      return;
    }
    
    for (int i = start; i < candidates.size(); i++) {
      if (i > start and candidates[i-1] == candidates[i])
        continue;
      
      if (candidates[i] <= target) {
        comb.emplace_back(candidates[i]);
        solve(candidates, target - candidates[i], solution, comb, i + 1);
        comb.pop_back();
      }
    }
  }
};