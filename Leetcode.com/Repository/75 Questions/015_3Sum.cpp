// https://leetcode.com/problems/3sum/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n^2)
// space: O(log(n)) to O(n) for sorting

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> ans;
    
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0)
        break;
      if (i > 0 && nums[i-1] == nums[i])
        continue;
      
      int l = i + 1, r = nums.size() - 1;
      
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum < 0)
          l++;
        else if (sum > 0)
          r--;
        else {
          ans.push_back({ nums[i], nums[l], nums[r] });
          l++;
          while (l < r && nums[l-1] == nums[l])
            l++;
        }
      }
    }
    
    return ans;
  }
};