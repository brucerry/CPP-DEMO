// https://leetcode.com/problems/subsets-ii/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * 2^n)
// space: O(n)
class Iterative {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> solutions(1), sub;
    for (int i = 0; i < nums.size(); i++) {
      if (i == 0 || nums[i - 1] != nums[i])
        sub = solutions;
      for (auto& j : sub)
        j.emplace_back(nums[i]);
      solutions.insert(solutions.end(), sub.begin(), sub.end());
    }
    return solutions;
  }
};

// time: O(n * 2^n)
// space: O(n)
class Recursive {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> solution;
    vector<int> subset;
    solve(nums, solution, subset, 0);
    return solution;
  }
  
private:
  void solve(vector<int>& nums, vector<vector<int>>& solution, vector<int>& subset, int start) {
    solution.emplace_back(subset);
    
    for (int i = start; i < nums.size(); i++) {
      if (i > start and nums[i-1] == nums[i])
        continue;
      subset.emplace_back(nums[i]);
      solve(nums, solution, subset, i + 1);
      subset.pop_back();
    }
  }
};