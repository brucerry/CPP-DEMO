// https://leetcode.com/problems/find-all-good-indices/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> goodIndices(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> inc (n, 1), dec (n, 1), result;

    for (int i = 1; i < n; i++) {
      if (nums[i-1] >= nums[i])
        dec[i] = dec[i-1] + 1;
    }

    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] <= nums[i+1])
        inc[i] = inc[i+1] + 1;
    }

    for (int i = k; i < n - k; i++) {
      if (inc[i+1] >= k and dec[i-1] >= k)
        result.emplace_back(i);
    }

    return result;
  }
};