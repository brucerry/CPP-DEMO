// https://leetcode.com/problems/minimum-average-difference/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n)
// space: O(n)
class Solution {
public:
  int minimumAverageDifference(vector<int>& nums) {
    int n = nums.size();
    vector<long> prefix (nums.begin(), nums.end());
    
    for (int i = 1; i < n; i++) {
      prefix[i] += prefix[i-1];
    }
    
    int minAvgDiff = INT_MAX, result = 0;
    for (int i = 0; i < n; i++) {
      int left_avg = prefix[i] / (i + 1);
      int right_avg = i == n - 1 ? 0 : (prefix.back() - prefix[i]) / (n - 1 - i);
      int diff = abs(left_avg - right_avg);
      if (diff < minAvgDiff) {
        minAvgDiff = diff;
        result = i;
      }
    }
    
    return result;
  }
};

// time: O(n)
// space: O(1)
class SpaceOptimized {
public:
  int minimumAverageDifference(vector<int>& nums) {
    int n = nums.size(), minAvgDiff = INT_MAX, result = 0;
    long prefix = 0, sum = accumulate(nums.begin(), nums.end(), 0L);

    for (int i = 0; i < n; i++) {
      prefix += nums[i];
      int left_avg = prefix / (i + 1);
      int right_avg = i == n - 1 ? 0 : (sum - prefix) / (n - 1 - i);
      int diff = abs(left_avg - right_avg);
      if (diff < minAvgDiff) {
        minAvgDiff = diff;
        result = i;
      }
    }
    
    return result;
  }
};