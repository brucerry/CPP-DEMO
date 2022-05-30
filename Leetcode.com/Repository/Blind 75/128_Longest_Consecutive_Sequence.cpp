// https://leetcode.com/problems/longest-consecutive-sequence/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet (nums.begin(), nums.end());
    
    int longest = 0;
    for (const int& num : nums) {
      if (numSet.count(num - 1) == 0) {
        int len = 0;
        while (numSet.count(num + len))
          len++;
        longest = max(longest, len);
      }
    }
    
    return longest;
  }
};