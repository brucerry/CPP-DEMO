// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_set>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    unordered_set<char> set;
    
    int l = 0;
    
    for (int r = 0; r < s.length(); r++) {
      while (set.count(s[r])) {
        set.erase(s[l++]);
      }
      set.insert(s[r]);
      ans = max(ans, r - l + 1);
    }
    
    return ans;
  }
};