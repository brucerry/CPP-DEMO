// https://leetcode.com/problems/backspace-string-compare/

#include <string>
using namespace std;

// s = len of s
// t = len of t
// time: O(max(s, t))
// space: O(1)

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    int i = s.size() - 1, j = t.size() - 1, backspace;
    while (i >= 0 or j >= 0) {
      backspace = 0;
      while (i >= 0 and (backspace or s[i] == '#')) {
        backspace += s[i] == '#' ? 1 : -1;
        i--;
      }
      backspace = 0;
      while (j >= 0 and (backspace or t[j] == '#')) {
        backspace += t[j] == '#' ? 1 : -1;
        j--;
      }
      if (i >= 0 and j >= 0 and s[i] == t[j]) {
        i--;
        j--;
      }
      else
        break;
    }
    return i == -1 and j == -1;
  }
};