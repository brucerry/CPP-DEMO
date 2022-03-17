// https://leetcode.com/problems/subsets/

#include <vector>
using namespace std;

// time: O(n * 2^n)
// space: O(n)

class Solution {
private:
  void solve(vector<int>& nums, vector<int> &candidate, vector<vector<int>> &solutions, int start) {
    solutions.emplace_back(candidate);
    for (int i = start; i < nums.size(); i++) {
      candidate.emplace_back(nums[i]);
      solve(nums, candidate, solutions, i + 1);
      candidate.pop_back();
    }
  }

public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> solutions;
    vector<int> candidate;
    solve(nums, candidate, solutions, 0);
    return solutions;
  }
};