// https://leetcode.com/problems/isomorphic-strings/

#include <string>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool isIsomorphic(string& s, string& t) {
    unordered_map<char, char> sMap, tMap;
    for (int i = 0; i < s.length(); i++) {
      if (sMap.count(s[i]) == 0 and tMap.count(t[i]) == 0) {
        sMap[s[i]] = t[i];
        tMap[t[i]] = s[i];
      }
      else if (sMap[s[i]] != t[i] or tMap[t[i]] != s[i])
        return false;
    }
    return true;
  }
};