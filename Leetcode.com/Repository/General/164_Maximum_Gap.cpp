// https://leetcode.com/problems/maximum-gap/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2)
      return 0;

    auto [ minIt, maxIt ] = minmax_element(nums.begin(), nums.end());
    int minNum = *minIt;
    int maxNum = *maxIt;

    if (maxNum == minNum)
      return 0;

    int interval = ceil((double)(maxNum - minNum) / (nums.size() - 1));
    int size = (maxNum - minNum) / interval + 1;
    vector<pair<int, int>> buckets (size, { INT_MAX, INT_MIN }); // minVal, maxVal

    for (const int& num : nums) {
      int index = (num - minNum) / interval;
      auto& [ minVal, maxVal ] = buckets[index];
      buckets[index] = { min(minVal, num), max(maxVal, num) };
    }

    int l = 0, gap = 0;
    for (int r = 0; r < buckets.size(); r++) {
      auto& [ leftMin, leftMax ] = buckets[l];
      auto& [ rightMin, rightMax ] = buckets[r];
      if (leftMax == INT_MIN)
        l++;
      if (rightMin != INT_MAX) {
        gap = max(gap, rightMin - leftMax);
        l = r;
      }
    }

    return gap;
  }
};