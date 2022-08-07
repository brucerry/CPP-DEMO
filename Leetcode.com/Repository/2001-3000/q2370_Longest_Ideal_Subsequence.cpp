// https://leetcode.com/problems/longest-ideal-subsequence/

#include <string>
using namespace std;

// time: O(n * k)
// space: O(26) => O(1)
class SpaceOptimized {
public:
  int longestIdealString(string& s, int k) {
    int dp[26] {}, longest = 0;
    for (const char& c : s) {
      int len = 0;
      for (int x = c - k; x <= c + k; x++) {
        if (x - 'a' >= 0 and x - 'a' <= 25)
          len = max(len, dp[x - 'a'] + 1);
      }
      longest = max(longest, dp[c - 'a'] = len);
    }
    return longest;
  }
};

// time: O(n * k)
// space: O(150) => O(1)
class UselessSpace {
public:
  int longestIdealString(string& s, int k) {
    int dp[150] {}, longest = 0;
    for (const char& c : s) {
      int len = 0;
      for (int x = c - k; x <= c + k; x++)
        len = max(len, dp[x] + 1);
      longest = max(longest, dp[c] = len);
    }
    return longest;
  }
};