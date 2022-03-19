// https://leetcode.com/problems/longest-consecutive-sequence/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numsSet (nums.begin(), nums.end());

    int ans = 0;
    for (int& num : nums) {
      if (numsSet.count(num - 1) == 0) {
        int count = 0;
        while (numsSet.count(num + count)) {
          count++;
        }
        ans = max(ans, count);
      }
    }

    return ans;
  }
};