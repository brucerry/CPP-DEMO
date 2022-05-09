// https://leetcode.com/problems/zigzag-conversion/

#include <string>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  string convert(string& s, int numRows) {
    if (numRows == 1)
      return s;
    
    int jump = (numRows - 1) << 1;
    
    string result;
    for (int r = 0; r < numRows; r++) {
      for (int i = r; i < s.length(); i += jump) {
        result += s[i];
        if (0 < r and r < numRows - 1 and i + jump - (r << 1) < s.length())
          result += s[i + jump - (r << 1)];
      }
    }
    
    return result;
  }
};