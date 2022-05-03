// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

#include <string>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  int minFlips(string& s) {
    int n = s.length();
    
    s += s;
    
    string alt1, alt2;
    for (int i = 0; i < s.length(); i++) {
      alt1 += (i & 1) ? "0" : "1";
      alt2 += (i & 1) ? "1" : "0";
    }
    
    int l = 0;
    int count = s.length();
    int diff1 = 0, diff2 = 0;
    for (int r = 0; r < s.length(); r++) {
      if (s[r] != alt1[r])
        diff1++;
      if (s[r] != alt2[r])
        diff2++;
      
      if (r - l + 1 > n) {
        if (s[l] != alt1[l])
          diff1--;
        if (s[l] != alt2[l])
          diff2--;
        l++;
      }
      
      if (r - l + 1 == n) {
        count = min({ count, diff1, diff2 });
      }
    }
    
    return count;
  }
};