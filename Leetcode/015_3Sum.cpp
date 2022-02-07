// https://leetcode.com/problems/3sum/

#include <vector>
#include <algorithm>
using namespace std;


// time: O(n * log(n)) + O(n^2) => O(n^2)
// space: O(log(n)) to O(n) for the extra space required by the sorting process
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {    
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i-1]) continue;

      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum > 0) right--;
        else if (sum < 0) left++;
        else {
          result.push_back({nums[i], nums[left], nums[right]});
          left++;
          while (left < right && nums[left] == nums[left-1]) left++;
        }
      }
    }

    return result;
  }
};