// https://leetcode.com/problems/valid-parenthesis-string/

#include <string>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  bool checkValidString(string s) {
    int countMin = 0, countMax = 0;
    
    for (const int& ch : s) {
      countMin += ch == '(' ? 1 : -1;
      countMax += ch == ')' ? -1 : 1;
      
      if (countMax < 0)
        return false;
      
      if (countMin < 0)
        countMin = 0;
    }
    
    return countMin == 0;
  }
};