// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_map>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0, left = 0, right = 0;
    int n = s.length();
    unordered_map<char, int> freq;

    while (right < n) {
      if (freq.count(s[right]) == 0) {
        ans = max(ans, right - left + 1);
        freq[s[right]]++;
      } else {
        while (s[left] != s[right]) {
          freq.erase(s[left]);
          left++;
        }
        left++;
      }
      right++;
    }

    return ans;
  }
};