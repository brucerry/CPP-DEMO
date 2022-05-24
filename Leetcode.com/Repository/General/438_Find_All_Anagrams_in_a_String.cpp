// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <vector>
#include <string>
#include <array>
using namespace std;

// time: O(s * 26) => O(s)
// space: O(26) => O(1)

class Solution {
public:
  vector<int> findAnagrams(string& s, string& p) {
    array<int, 26> sCount { 0 }, pCount { 0 };
    for (const char& c : p)
      pCount[c - 'a']++;
    
    vector<int> result;
    int l = 0;
    for (int r = 0; r < s.length(); r++) {
      char c = s[r];
      sCount[c - 'a']++;
      
      if (r - l + 1 > p.length()) {
        sCount[s[l] - 'a']--;
        l++;
      }
      
      if (r - l + 1 == p.length() and sCount == pCount)
        result.emplace_back(l);
    }
    
    return result;
  }
};