// https://leetcode.com/problems/subsets/

#include <vector>
using namespace std;

// time: O(n * 2^n)
// space: O(n)

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> solution;
    vector<int> state;
    solve(nums, solution, state, 0);
    return solution;
  }
  
private:
  void solve(vector<int>& nums, vector<vector<int>>& solution, vector<int>& state, int start) {
    solution.emplace_back(state);
    
    for (int i = start; i < nums.size(); i++) {
      state.emplace_back(nums[i]);
      solve(nums, solution, state, i + 1);
      state.pop_back();
    }
  }
};