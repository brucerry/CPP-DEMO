// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int lengthOfLongestSubstring(string& s) {
    unordered_set<char> charSet;
    
    int longest = 0;
    int l = 0;
    for (int r = 0; r < s.length(); r++) {
      while (charSet.count(s[r])) {
        charSet.erase(s[l++]);
      }
      charSet.emplace(s[r]);
      longest = max(longest, r - l + 1);
    }
    
    return longest;
  }
};