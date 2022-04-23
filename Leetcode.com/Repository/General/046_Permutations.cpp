// https://leetcode.com/problems/permutations/

#include <vector>
using namespace std;

// time: O(n * n!)
// space: O(n)

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.size() == 1)
      return { nums };
    
    int numTaken = nums[0];
    vector<int> remain = vector<int>(nums.begin() + 1, nums.end());
    
    vector<vector<int>> ans;
    
    for (auto& remainPermute : permute(remain)) {
      int len = remainPermute.size();
      for (int i = 0; i <= len; i++) {
        remainPermute.insert(remainPermute.begin() + i, numTaken);
        ans.emplace_back(remainPermute);
        remainPermute.erase(remainPermute.begin() + i);
      }
    }
    
    return ans;
  }

  // vector<vector<int>> permute(vector<int>& nums) {
  //   if (nums.size() == 1)
  //     return { nums };

  //   vector<vector<int>> result;

  //   for (int i = 0; i < nums.size(); i++) {
  //     int numTaken = nums[0];
  //     nums.erase(nums.begin());
  //     for (auto& remainPermute : permute(nums)) {
  //       remainPermute.emplace_back(numTaken);
  //       result.emplace_back(remainPermute);
  //     }
  //     nums.emplace_back(numTaken);
  //   }

  //   return result;
  // }
};