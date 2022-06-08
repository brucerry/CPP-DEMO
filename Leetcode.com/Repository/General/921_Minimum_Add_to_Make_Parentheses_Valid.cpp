// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minAddToMakeValid(string& s) {
    int open = 0, close = 0;
    for (const char& c : s) {
      if (c == '(')
        open++;
      else if (open)
        open--;
      else
        close++;
    }
    return open + close;
  }
};