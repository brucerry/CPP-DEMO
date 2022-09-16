// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

#include <string>
#include <cstring>
using namespace std;

// time: O(n * 26) => O(n)
// space: O(26) => O(1)

class Solution {
public:
  int longestSubstring(string& s, int k) {
    int maxUnique = getMaxUnique(s), result = 0, charCount[26];
    
    for (int curUnique = 1; curUnique <= maxUnique; curUnique++) {
      memset(charCount, 0, sizeof(charCount));
      for (int l = 0, r = 0, unique = 0, countAtLeastK = 0; r < s.length();) {
        if (unique <= curUnique) {
          int idx = s[r++] - 'a';
          if (charCount[idx]++ == 0)
            unique++;
          if (charCount[idx] == k)
            countAtLeastK++;
        }
        else {
          int idx = s[l++] - 'a';
          if (charCount[idx]-- == k)
            countAtLeastK--;
          if (charCount[idx] == 0)
            unique--;
        }
        
        if (unique == curUnique and unique == countAtLeastK)
          result = max(result, r - l);
      }
    }
    
    return result;
  }
  
private:
  int getMaxUnique(string& s) {
    int mask = 0;
    for (const char& c : s) {
      mask |= 1 << (c - 'a');
    }
    return __builtin_popcount(mask);
  }
};