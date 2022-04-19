// https://leetcode.com/problems/decode-ways/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int numDecodings(string s) {
    int i_plus_1 = 0;
    int ans = 1;
    
    for (int i = s.length() - 1; i >= 0; i--) {
      int tmp = ans;
      
      if (s[i] == '0') {
        ans = 0;
      }
      else if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && '0' <= s[i+1] && s[i+1] <= '6'))) {
        ans += i_plus_1;
      }
      
      i_plus_1 = tmp;
    }
    
    return ans;
  }
};