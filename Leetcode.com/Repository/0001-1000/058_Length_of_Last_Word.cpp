// https://leetcode.com/problems/length-of-last-word/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int lengthOfLastWord(string s) {
    int result = 0, n = s.size();
    for (int i = n - 1; i >= 0; i--) {
      if (i + 1 < n and s[i] == ' ' and s[i+1] != ' ')
        break;
      result += s[i] != ' ';
    }
    return result;
  }
};