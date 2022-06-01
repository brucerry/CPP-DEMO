// https://leetcode.com/problems/decode-ways/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int numDecodings(string& s) {
    int one = 1, two = 0;
    
    for (int i = s.length() - 1; i >= 0; i--) {
      int tmp = s[i] == '0' ? 0 : one;
      
      if (i + 1 < s.length() and (s[i] == '1' or (s[i] == '2' and '0' <= s[i+1] and s[i+1] <= '6')))
        tmp += two;
      
      two = one;
      one = tmp;
    }
    
    return one;
  }
};