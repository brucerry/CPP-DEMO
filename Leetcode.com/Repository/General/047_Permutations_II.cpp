// https://leetcode.com/problems/permutations-ii/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n * n!)
// space: O(n)

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    unordered_map<int, int> intCount;
    for (const int& num : nums)
      intCount[num]++;
    
    vector<vector<int>> ans;
    vector<int> perm;
    solve(nums, intCount, ans, perm);
    return ans;
  }
  
private:
  void solve(vector<int>& nums, unordered_map<int, int>& intCount, vector<vector<int>>& ans, vector<int>& perm) {
    if (perm.size() == nums.size()) {
      ans.emplace_back(perm);
      return;
    }
    
    for (auto& [ num, count ] : intCount) {
      if (count) {
        count--;
        
        perm.emplace_back(num);
        solve(nums, intCount, ans, perm);
        perm.pop_back();
        
        count++;
      }
    }
  }
};