// https://leetcode.com/problems/regular-expression-matching/

#include <string>
#include <array>
using namespace std;

// time: O(s * p)
// space: O(s * p)

class Solution {
private:
  bool isMatch(string& s, string& p, int i, int j, array<array<int, 30>, 30>& memo) {
    if (i < s.length() && j < p.length() && memo[i][j] != -1) return memo[i][j];
    if (i >= s.length() && j >= p.length()) return true;
    if (j >= p.length()) return false;

    bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');

    if (j + 1 < p.length() && p[j + 1] == '*') {
      return memo[i][j] = isMatch(s, p, i, j + 2, memo) || (match && isMatch(s, p, i + 1, j, memo));
    }

    if (match) {
      return memo[i][j] = isMatch(s, p, i + 1, j + 1, memo);
    }

    return memo[i][j] = false;
  }

public:
  bool isMatch(string s, string p) {
    array<array<int, 30>, 30> memo;
    memset(&memo, -1, sizeof(memo));
    return isMatch(s, p, 0, 0, memo);
  }
};