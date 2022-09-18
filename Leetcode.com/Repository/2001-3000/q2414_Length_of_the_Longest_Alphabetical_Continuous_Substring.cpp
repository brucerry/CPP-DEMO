// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int longestContinuousSubstring(string& s) {
    int result = 1;
    for (int len = 1, i = 1; i < s.length(); i++) {
      if (s[i-1] + 1 == s[i])
        len++;
      else
        len = 1;
      result = max(result, len);
    }
    return result;
  }
};