// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int result = 1;
    for (int l = 0, r = 0; r < nums.size(); r++) {
      if (nums[r] - nums[l] > k) {
        result++;
        l = r;
      }
    }
    return result;
  }
};