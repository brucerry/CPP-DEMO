// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    
    unsigned long curSum = 0;
    int maxFreq = 0;
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      curSum += nums[r];
      while ((unsigned long)nums[r] * (r - l + 1) > curSum + k) {
        curSum -= nums[l];
        l++;
      }
      maxFreq = max(maxFreq, r - l + 1);
    }
    return maxFreq;
  }
};