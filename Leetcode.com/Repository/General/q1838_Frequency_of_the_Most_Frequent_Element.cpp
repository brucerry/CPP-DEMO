// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) to O(n) for sorting

class Solution {
public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    
    int l = 0;
    unsigned long curSum = 0;
    int len = 0;
    for (int r = 0; r < nums.size(); r++) {
      curSum += nums[r];
      
      while ((unsigned long)nums[r] * (r - l + 1) > curSum + k) {
        curSum -= nums[l];
        l++;
      }
      
      len = max(len, r - l + 1);
    }
    
    return len;
  }
};