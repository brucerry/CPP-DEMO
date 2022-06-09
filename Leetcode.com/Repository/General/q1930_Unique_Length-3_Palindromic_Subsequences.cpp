// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

#include <string>
#include <array>
using namespace std;

// time: O(26 * n) => O(n)
// space: O(26) => O(1)

class Solution {
public:
  int countPalindromicSubsequence(string& s) {
    array<int, 26> usedMask { 0 };
    
    int count = 0;
    for (const char& c : s) {
      if (usedMask[c - 'a'] == 0) {
        int l = s.find(c) + 1, r = s.rfind(c) - 1;
        while (l <= r) {
          if ((usedMask[c - 'a'] & (1 << (s[l] - 'a'))) == 0) {
            usedMask[c - 'a'] |= (1 << (s[l] - 'a'));
            count++;
          }
          l++;
        }
      }
    }
    return count;
  }
};