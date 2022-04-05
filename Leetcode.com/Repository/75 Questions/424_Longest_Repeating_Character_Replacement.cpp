// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <string>
#include <array>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  int characterReplacement(string s, int k) {
    array<int, 26> charCount { 0 };
    
    int maxFreq = 0;
    int ans = 0;
    int l = 0;
    
    for (int r = 0; r < s.length(); r++) {
      charCount[s[r] - 'A']++;
      maxFreq = max(maxFreq, charCount[s[r] - 'A']);
      
      while (r - l + 1 - maxFreq > k) {
        charCount[s[l] - 'A']--;
        l++;
      }
      
      ans = max(ans, r - l + 1);
    }
    
    return ans;
  }
};