// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include <vector>
#include <algorithm>
using namespace std;

// max = max of nums
// time: O(n * log(n) + n * log(max))
// space: O(log(n)) for sorting

class Solution {
public:
  int smallestDivisor(vector<int>& nums, int threshold) {
    sort(nums.begin(), nums.end());
    int l = 1, r = nums.back();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (canSum(nums, threshold, m))
        r = m;
      else
        l = m + 1;
    }
    return r;
  }

private:
  bool canSum(vector<int>& nums, int threshold, int divisor) {
    int sum = 0;
    for (const int& num : nums) {
      sum += (num + divisor - 1) / divisor;
    }
    return sum <= threshold;
  }
};
