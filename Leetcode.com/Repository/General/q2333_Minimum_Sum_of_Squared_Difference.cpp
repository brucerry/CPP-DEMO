// https://leetcode.com/problems/minimum-sum-of-squared-difference/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    int n = nums1.size();
    
    int maxDiff = 0;
    for (int i = 0; i < n; i++) {
      int diff = abs(nums1[i] - nums2[i]);
      maxDiff = max(maxDiff, diff);
    }
    
    vector<int> freqs (maxDiff + 1);
    for (int i = 0; i < n; i++) {
      int diff = abs(nums1[i] - nums2[i]);
      freqs[diff]++;
    }
    
    int quota = k1 + k2;
    for (int diff = maxDiff; diff and quota; diff--) {
      if (freqs[diff]) {
        int minus = min(quota, freqs[diff]);
        freqs[diff] -= minus;
        freqs[diff-1] += minus;
        quota -= minus;
      }
    }
    
    long long sum = 0;
    for (long long diff = maxDiff; diff; diff--) {
      sum += diff * diff * freqs[diff];
    }
    
    return sum;
  }
};