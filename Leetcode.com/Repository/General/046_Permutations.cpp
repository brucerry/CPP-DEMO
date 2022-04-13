// https://leetcode.com/problems/permutations/

#include <vector>
using namespace std;

// time: O(n!)
// space: O(n!)

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.size() == 1)
      return { nums };
    
    vector<int> withoutFirst = vector<int>(nums.begin() + 1, nums.end());
    
    vector<vector<int>> ans;
    
    for (auto& p : permute(withoutFirst)) {
      int len = p.size();
      for (int i = 0; i <= len; i++) {
        p.emplace(p.begin() + i, nums[0]);
        ans.emplace_back(p);
        p.erase(p.begin() + i);
      }
    }
    
    return ans;
  }

  // vector<vector<int>> permute(vector<int>& nums) {
  //   if (nums.size() == 1) return { nums };

  //   vector<vector<int>> result;

  //   for (int i = 0; i < nums.size(); i++) {
  //     int numTaken = nums[0];
  //     nums.erase(nums.begin());
  //     for (auto remainPermute : permute(nums)) {
  //       remainPermute.push_back(numTaken);
  //       result.push_back(remainPermute);
  //     }
  //     nums.push_back(numTaken);
  //   }

  //   return result;
  // }
};