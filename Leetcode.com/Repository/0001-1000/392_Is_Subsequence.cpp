// https://leetcode.com/problems/is-subsequence/

#include <string>
using namespace std;

// s = len of s
// t = len of t
// time: O(min(s, t))
// space: O(1)

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int s_len = s.size(), t_len = t.size(), i = 0;
    for (int j = 0; i < s_len and j < t_len; j++) {
      if (s[i] == t[j])
        i++;
    }
    return i == s_len;
  }
};