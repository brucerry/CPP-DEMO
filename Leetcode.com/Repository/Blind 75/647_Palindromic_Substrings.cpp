// https://leetcode.com/problems/palindromic-substrings/

#include <string>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  int countSubstrings(string& s) {
    int count = 0;
    
    for (int i = 0; i < s.length(); i++) {
      // odd
      int l = i, r = i;
      while (0 <= l and r < s.length() and s[l] == s[r]) {
        count++;
        l--;
        r++;
      }

      // even
      l = i, r = i + 1;
      while (0 <= l and r < s.length() and s[l] == s[r]) {
        count++;
        l--;
        r++;
      }
    }
    
    return count;
  }
};