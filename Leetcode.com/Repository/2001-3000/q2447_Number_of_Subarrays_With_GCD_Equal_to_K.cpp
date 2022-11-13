// https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/

#include <vector>
#include <numeric>
using namespace std;

// gcd = time for gcd()
// time: O(n^2 * gcd)
// space: O(1)

class Solution {
public:
  int subarrayGCD(vector<int>& nums, int k) {
    int result = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i, GCD = nums[i]; j < n; j++) {
        GCD = gcd(GCD, nums[j]);
        result += GCD == k;
      }
    }
    return result;
  }
};