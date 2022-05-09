// https://leetcode.com/problems/3sum/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n^2)
// space: O(log(n)) for sorting

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> triplets;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0)
        break;
      if (i > 0 and nums[i-1] == nums[i])
        continue;
      
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum > 0)
          r--;
        else if (sum < 0)
          l++;
        else {
          triplets.push_back({ nums[i], nums[l], nums[r] });
          l++;
          while (l < r and nums[l-1] == nums[l])
            l++;
        }
      }
    }
    
    return triplets;
  }
};