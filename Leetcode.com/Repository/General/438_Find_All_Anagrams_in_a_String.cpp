// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <vector>
#include <string>
#include <array>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  vector<int> findAnagrams(string& s, string& p) {
    if (s.length() < p.length())
      return {};
    
    array<char, 26> pCount { 0 }, sCount { 0 };
    
    for (int i = 0; i < p.length(); i++) {
      pCount[p[i] - 'a']++;
      sCount[s[i] - 'a']++;
    }
    
    vector<int> ans;
    
    if (pCount == sCount)
      ans.emplace_back(0);
    
    int l = 0, r = p.length();
    
    while (r < s.length()) {
      sCount[s[l] - 'a']--;
      sCount[s[r] - 'a']++;
      
      l++;
      r++;
      
      if (pCount == sCount)
        ans.emplace_back(l);
    }
    
    return ans;
  }
};