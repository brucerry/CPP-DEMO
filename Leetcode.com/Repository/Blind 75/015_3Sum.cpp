// https://leetcode.com/problems/3sum/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n^2)
// space: O(log(n)) for sorting

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3)
      return {};
    
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    vector<vector<int>> result;
    for (int i = 0; i < n; i++) {
      if (i and nums[i-1] == nums[i])
        continue;
      
      int l = i + 1, r = n - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        
        if (sum < 0)
          l++;
        else if (sum > 0)
          r--;
        else {
          result.push_back({ nums[i], nums[l], nums[r] });
          l++;
          while (l < r and nums[l-1] == nums[l])
            l++;
        }
      }
    }
    
    return result;
  }
};