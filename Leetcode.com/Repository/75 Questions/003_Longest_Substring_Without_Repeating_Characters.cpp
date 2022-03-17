// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_set>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  int lengthOfLongestSubstring(string& s) {
    int ans = 0, left = 0, right = 0;
    unordered_set<char> charSet;

    while (right < s.length()) {
      while (charSet.count(s[right])) {
        charSet.erase(s[left]);
        left++;
      }
      charSet.insert(s[right]);
      ans = max(ans, right - left + 1);
      right++;
    }

    return ans;
  }
};