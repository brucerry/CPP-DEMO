// https://leetcode.com/problems/permutations/

#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.size() == 1) return { nums };

    vector<vector<int>> result;
    vector<int> numsRemain (nums.begin() + 1, nums.end());

    for (auto permuteRemain : permute(numsRemain)) {
      int len = permuteRemain.size();
      for (int i = 0; i <= len; i++) {
        permuteRemain.insert(permuteRemain.begin() + i, nums[0]);
        result.push_back(permuteRemain);
        permuteRemain.erase(permuteRemain.begin() + i);
      }
    }

    return result;
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