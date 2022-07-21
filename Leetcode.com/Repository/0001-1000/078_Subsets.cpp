// https://leetcode.com/problems/subsets/

#include <vector>
using namespace std;

// time: O(n * 2^n)
// space: O(n)

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> solution;
    vector<int> subset;
    solve(nums, solution, subset, 0);
    return solution;
  }
  
private:
  void solve(vector<int>& nums, vector<vector<int>>& solution, vector<int>& subset, int start) {
    solution.emplace_back(subset);
    
    for (int i = start; i < nums.size(); i++) {
      subset.emplace_back(nums[i]);
      solve(nums, solution, subset, i + 1);
      subset.pop_back();
    }
  }
};