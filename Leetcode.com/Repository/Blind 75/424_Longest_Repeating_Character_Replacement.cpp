// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <string>
#include <array>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  int characterReplacement(string& s, int k) {
    array<int, 26> charCount { 0 };
    
    int longest = 0, maxFreq = 0;
    int l = 0;
    for (int r = 0; r < s.length(); r++) {
      charCount[s[r] - 'A']++;
      maxFreq = max(maxFreq, charCount[s[r] - 'A']);
      while (r - l + 1 - maxFreq > k) {
        charCount[s[l] - 'A']--;
        l++;
      }
      longest = max(longest, r - l + 1);
    }
    
    return longest;
  }
};