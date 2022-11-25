// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <string>
#include <cstring>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int memo[1000][1000];
    memset(memo, -1, sizeof(memo));
    return solve(s, memo, 0, s.size() - 1);
  }

private:
  int solve(string& s, int (*memo)[1000], int l, int r) {
    if (l > r)
      return 0;

    if (l == r)
      return 1;

    int& res = memo[l][r];

    if (res != -1)
      return res;

    if (s[l] != s[r])
      res = max(solve(s, memo, l, r - 1), solve(s, memo, l + 1, r));
    else
      res = 2 + solve(s, memo, l + 1, r - 1);

    return res;
  }
};