// https://leetcode.com/problems/valid-parenthesis-string/

#include <string>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  bool checkValidString(string& s) {
    int minCount = 0, maxCount = 0;
    for (const char& c : s) {
      minCount += c == '(' ? 1 : -1;
      maxCount += c == ')' ? -1 : 1;
      
      if (maxCount < 0)
        return false;
      if (minCount < 0)
        minCount = 0;
    }
    return minCount == 0;
  }
};