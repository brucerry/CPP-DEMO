// https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n * log(n))
// space: O(1)

class Solution {
public:
  int waysToSplit(vector<int>& nums) {
    partial_sum(nums.begin(), nums.end(), nums.begin());
    int result = 0;
    for (int i = 1; i < nums.size() - 1; i++) {
      int l = search(nums, nums[i-1], i, true);
      int r = search(nums, nums[i-1], i, false);
      if (l == -1 or r == -1)
        continue;
      result = (result + (r - l + 1)) % 1000000007;
    }
    return result;
  }

private:
  int search(vector<int>& nums, int leftsum, int l, bool leftBiased) {
    int index = -1, r = nums.size() - 2;
    while (l <= r) {
      int m = l + (r - l) / 2;
      int midsum = nums[m] - leftsum, rightsum = nums.back() - nums[m];
      if (leftsum <= midsum and midsum <= rightsum) {
        index = m;
        if (leftBiased)
          r = m - 1;
        else
          l = m + 1;
      }
      else if (leftsum > midsum)
        l = m + 1;
      else
        r = m - 1;
    }
    return index;
  }
};