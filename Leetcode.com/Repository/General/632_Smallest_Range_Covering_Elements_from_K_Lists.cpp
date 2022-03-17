// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<pair<int, int>> mergedNums;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums[i].size(); j++) {
        mergedNums.push_back({nums[i][j], i});
      }
    }

    sort(mergedNums.begin(), mergedNums.end());

    int minLeft = mergedNums[0].first;
    int minRight = mergedNums.back().first;
    int minRange = minRight - minLeft;

    const int k = nums.size();
    int total;
    vector<int> freq (k, 0);

    int left = 0;
    int right = 0;

    while (right < mergedNums.size()) {
      freq[mergedNums[right].second]++;
      if (freq[mergedNums[right].second] == 1) total++;

      if (total == k) {
        while (left < right && freq[mergedNums[left].second] > 1) {
          freq[mergedNums[left].second]--;
          left++;
        }

        int range = mergedNums[right].first - mergedNums[left].first;
        if (range < minRange) {
          minLeft = mergedNums[left].first;
          minRight = mergedNums[right].first;
          minRange = range;
        }

        freq[mergedNums[left].second]--;
        left++;
        total--;
      }

      right++;
    }

    return {minLeft, minRight};
  }
};