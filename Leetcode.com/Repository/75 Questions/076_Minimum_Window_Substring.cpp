// https://leetcode.com/problems/minimum-window-substring/

#include <string>
#include <unordered_map>
using namespace std;

// time: O(s + t)
// space: O(s + t)

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> charCountT, charCountS;
    
    for (char& ch : t) {
      charCountT[ch]++;
    }
    
    int minLen = s.length();
    int startIndex = 0;
    int l = 0;
    int satisfied = 0;
    
    for (int r = 0; r < s.length(); r++) {
      const char& ch = s[r];
      charCountS[ch]++;
      
      if (satisfied < charCountT.size() && charCountT.count(ch) && charCountT[ch] == charCountS[ch]) {
        satisfied++;
      }
      
      if (satisfied == charCountT.size()) {
        while (charCountT.count(s[l]) == 0 || charCountS[s[l]] > charCountT[s[l]]) {
          charCountS[s[l]]--;
          l++;
        }
        const int len = r - l + 1;
        if (len < minLen) {
          minLen = len;
          startIndex = l;
        }
      }
    }
    
    return satisfied == charCountT.size() ? s.substr(startIndex, minLen) : "";
  }
};