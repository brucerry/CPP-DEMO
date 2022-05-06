// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

#include <string>
#include <array>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int countPalindromicSubsequence(string& s) {
    array<int, 26> usedMasks { 0 };
    int count = 0;
    
    for (int i = 0; i < s.length(); i++) {      
      if (usedMasks[s[i] - 'a'])
        continue;
      
      int l = i + 1, r = s.length() - 1;
      while (l < r and s[r] != s[i])
        r--;

      for (int j = l; j < r; j++) {
        if ((usedMasks[s[i] - 'a'] & (1 << (s[j] - 'a'))) == 0) {
          count++;
          usedMasks[s[i] - 'a'] |= (1 << (s[j] - 'a'));
        }
      }
    }
    
    return count;
  }
};