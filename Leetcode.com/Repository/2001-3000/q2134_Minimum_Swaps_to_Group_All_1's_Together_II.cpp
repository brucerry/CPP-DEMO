// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minSwaps(vector<int>& nums) {
    int ones = count(nums.begin(), nums.end(), 1), n = nums.size(), swaps = n;
    for (int l = 0, r = 0, curOnes = 0; l < n; l++) {
      while (r - l + 1 <= ones)
        curOnes += nums[r++ % n];
      swaps = min(swaps, ones - curOnes);
      curOnes -= nums[l];
    }
    return swaps;
  }
};