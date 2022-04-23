// https://leetcode.com/problems/subsets-ii/


#include <iostream>
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

class Recursive {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> candidate;
    solve(nums, ans, candidate, 0);
    return ans;
  }
  
private:
  void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& candidate, int start) {
    ans.emplace_back(candidate);
    for (int i = start; i < nums.size(); i++) {
      if (i > start && nums[i-1] == nums[i])
        continue;
      candidate.emplace_back(nums[i]);
      solve(nums, ans, candidate, i + 1);
      candidate.pop_back();
    }
  }
};