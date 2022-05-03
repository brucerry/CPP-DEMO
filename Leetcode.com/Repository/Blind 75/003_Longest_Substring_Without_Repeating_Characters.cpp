// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_set>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  int lengthOfLongestSubstring(string& s) {
    int l = 0;
    int len = 0;
    unordered_set<char> charSet;
    
    for (int r = 0; r < s.length(); r++) {
      while (charSet.count(s[r])) {
        charSet.erase(s[l]);
        l++;
      }
      charSet.emplace(s[r]);
      len = max(len, r - l + 1);
    }
    
    return len;
  }
};