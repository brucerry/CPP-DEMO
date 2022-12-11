// https://leetcode.com/problems/longest-square-streak-in-an-array/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int longestSquareStreak(vector<int>& nums) {
    unordered_set<long> uset (nums.begin(), nums.end());
    int res = 0;
    for (const int& num : nums) {
      int count = 0;
      for (long i = num; uset.count(i); i *= i, count++);
      res = max(res, count);
    }
    return res < 2 ? -1 : res;
  }
};