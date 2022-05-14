// https://leetcode.com/problems/isomorphic-strings/

#include <string>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool isIsomorphic(string& s, string& t) {
    unordered_map<char, char> sMap;
    unordered_map<char, char> tMap;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
      if ((sMap.count(s[i]) and sMap[s[i]] != t[i]) or
          (tMap.count(t[i]) and tMap[t[i]] != s[i]))
        return false;
      sMap[s[i]] = t[i];
      tMap[t[i]] = s[i];
    }
    
    return true;
  }
};