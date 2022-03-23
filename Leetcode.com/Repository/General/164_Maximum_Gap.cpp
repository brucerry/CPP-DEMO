// https://leetcode.com/problems/maximum-gap/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;

    int maxNum = *max_element(nums.begin(), nums.end());
    int minNum = *min_element(nums.begin(), nums.end());
  
    if (maxNum == minNum) return 0;

    int interval = ceil((double)(maxNum - minNum) / (nums.size() - 1));
    int bucketsLen = (maxNum - minNum) / interval + 1;
    vector<pair<int, int>> buckets (bucketsLen, {INT_MAX, INT_MIN});

    for (int& num : nums) {
      int index = (num - minNum) / interval;
      int curMin = buckets[index].first;
      int curMax = buckets[index].second;
      buckets[index] = { min(curMin, num), max(curMax, num) };
    }

    int ans = 0;
    int l = 0;
    int r = 0;
    
    while (r < buckets.size()) {
      if (buckets[l].first == INT_MAX) l++;
      
      if (buckets[r].first != INT_MAX) {
        ans = max(ans, buckets[r].first - buckets[l].second);
        l = r;
      }
      r++;
    }

    return ans;
  }
};