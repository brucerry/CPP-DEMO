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
    
    int len = 0, mostFreq = 0;
    int l = 0;
    for (int r = 0; r < s.length(); r++) {
      charCount[s[r] - 'A']++;
      mostFreq = max(mostFreq, charCount[s[r] - 'A']);
      while (r - l + 1 - mostFreq > k) {
        charCount[s[l] - 'A']--;
        l++;
      }
      len = max(len, r - l + 1);
    }
    
    return len;
  }
};