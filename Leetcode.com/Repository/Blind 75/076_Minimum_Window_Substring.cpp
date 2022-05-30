// https://leetcode.com/problems/minimum-window-substring/

#include <string>
#include <unordered_map>
using namespace std;

// time: O(s + t)
// space: O(s + t)

class Solution {
public:
  string minWindow(string& s, string& t) {
    unordered_map<char, int> sCount, tCount; // char, count
    for (const char& c : t)
      tCount[c]++;
    
    int minLen = INT_MAX, startIndex = -1;
    int match = 0;
    int l = 0;
    for (int r = 0; r < s.length(); r++) {
      char c = s[r];
      sCount[c]++;
      
      if (match < tCount.size() and tCount.count(c) and sCount[c] == tCount[c])
        match++;
      
      if (match == tCount.size()) {
        while (tCount.count(s[l]) == 0 or sCount[s[l]] > tCount[s[l]]) {
          sCount[s[l]]--;
          l++;
        }
        if (r - l + 1 < minLen) {
          minLen = r - l + 1;
          startIndex = l;
        }
      }
    }
    
    return startIndex == -1 ? "" : s.substr(startIndex, minLen);
  }
};