// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <string>
#include <unordered_map>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  int characterReplacement(string& s, int k) {
    unordered_map<char, int> charCount;

    int ans = 0;
    int maxFreq = 0;
    int l = 0;

    for (int r = 0; r < s.length(); r++) {
      charCount[s[r]]++;
      maxFreq = max(maxFreq, charCount[s[r]]);

      while (r - l + 1 - maxFreq > k) {
        charCount[s[l]]--;
        l++;
      }

      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};