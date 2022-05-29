// https://leetcode.com/problems/permutations/

#include <vector>
using namespace std;

// time: O(n * n!)
// space: O(n)

class Solution1 {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> solution;
    vector<int> permute;
    solve(nums.size(), nums, solution, permute);
    return solution;
  }
  
private:
  void solve(int n, vector<int>& nums, vector<vector<int>>& solution, vector<int>& permute) {
    if (n == permute.size()) {
      solution.emplace_back(permute);
      return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      nums.erase(nums.begin() + i);
      permute.emplace_back(num);
      solve(n, nums, solution, permute);
      permute.pop_back();
      nums.emplace(nums.begin() + i, num);
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