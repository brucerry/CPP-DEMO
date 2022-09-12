// https://leetcode.com/problems/score-of-parentheses/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int scoreOfParentheses(string& s) {
    int result = 0;
    for (int outer_layer = 0, i = 0; i < s.length(); i++) {
      outer_layer += s[i] == '(' ? 1 : -1;
      if (s[i] == ')' and s[i-1] == '(')
        result += 1 << outer_layer;
    }
    return result;
  }
};