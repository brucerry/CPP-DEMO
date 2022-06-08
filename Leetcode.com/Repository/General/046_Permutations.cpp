// https://leetcode.com/problems/permutations/

#include <vector>
using namespace std;

// time: O(n * n!)
// space: O(n)

class Solution1 {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> solution;
    vector<int> perm;
    solve(nums.size(), nums, solution, perm);
    return solution;
  }
  
private:
  void solve(int n, vector<int>& nums, vector<vector<int>>& solution, vector<int>& perm) {
    if (perm.size() == n) {
      solution.emplace_back(perm);
      return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
      perm.emplace_back(nums[i]);
      nums.erase(nums.begin() + i);
      solve(n, nums, solution, perm);
      nums.emplace(nums.begin() + i, perm.back());
      perm.pop_back();
    }
  }
};

class Solution2 {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.size() == 1)
      return { nums };
    
    int numTaken = nums[0];
    nums.erase(nums.begin());
    
    vector<vector<int>> result;
    for (auto& rp : permute(nums)) {
      int len = rp.size();
      for (int i = 0; i <= len; i++) {
        rp.emplace(rp.begin() + i, numTaken);
        result.emplace_back(rp);
        rp.erase(rp.begin() + i);
      }
    }
    
    return result;
  }
};

class Solution3 {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.size() == 1)
      return { nums };

    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i++) {
      int numTaken = nums[0];
      nums.erase(nums.begin());
      for (auto& rp : permute(nums)) {
        rp.emplace_back(numTaken);
        result.emplace_back(rp);
      }
      nums.emplace_back(numTaken);
    }

    return result;
  }
};