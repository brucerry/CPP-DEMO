// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_set>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int l = 0;
    int ans = 0;
    
    for (int r = 0; r < s.length(); r++) {
      while (set.count(s[r])) {
        set.erase(s[l]);
        l++;
      }
      set.emplace(s[r]);
      ans = max(ans, r - l + 1);
    }
    
    return ans;
  }
};