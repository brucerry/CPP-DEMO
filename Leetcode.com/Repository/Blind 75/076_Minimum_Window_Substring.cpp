// https://leetcode.com/problems/minimum-window-substring/

#include <string>
#include <unordered_map>
using namespace std;

// time: O(s + t)
// space: O(s + t)

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> charCountS, charCountT;
    
    for (const char& ch : t) {
      charCountT[ch]++;
    }
    
    int l = 0;
    int matches = 0;
    int startIndex = 0, minLen = INT_MAX;
    
    for (int r = 0; r < s.length(); r++) {
      charCountS[s[r]]++;
      
      if (matches < charCountT.size() && charCountT.count(s[r]) && charCountS[s[r]] == charCountT[s[r]])
        matches++;
      
      if (matches == charCountT.size()) {
        while (charCountT.count(s[l]) == 0 || charCountS[s[l]] > charCountT[s[l]]) {
          charCountS[s[l]]--;
          l++;
        }
        if (r - l + 1 < minLen) {
          minLen = r - l + 1;
          startIndex = l;
        }
      }
    }
    
    return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
  }
};