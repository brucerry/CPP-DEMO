// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <vector>
#include <string>
#include <array>
using namespace std;

// time: O(s)
// space: O(1)
class Optimizied {
public:
  vector<int> findAnagrams(string& s, string& p) {
    int m = s.length();
    int n = p.length();
    
    if (m < n)
      return {};
    
    array<int, 26> sCount { 0 }, pCount { 0 };
    for (int i = 0; i < n; i++) {
      sCount[s[i] - 'a']++;
      pCount[p[i] - 'a']++;
    }
    
    int match = 0;
    for (int i = 0; i < 26; i++) {
      if (sCount[i] == pCount[i])
        match++;
    }
    
    vector<int> result;
    if (match == 26)
      result.emplace_back(0);
    
    for (int l = 0, r = n; r < m; l++, r++) {
      int r_index = s[r] - 'a';
      int l_index = s[l] - 'a';
      
      sCount[r_index]++;
      if (sCount[r_index] == pCount[r_index])
        match++;
      else if (sCount[r_index] == pCount[r_index] + 1)
        match--;
      
      sCount[l_index]--;
      if (sCount[l_index] == pCount[l_index])
        match++;
      else if (sCount[l_index] == pCount[l_index] - 1)
        match--;
      
      if (match == 26)
        result.emplace_back(l + 1);
    }
    
    return result;
  }
};

// time: O(s * 26) => O(s)
// space: O(26 * 2) => O(1)
class ArrayComparison {
public:
  vector<int> findAnagrams(string& s, string& p) {
    array<int, 26> sCount { 0 }, pCount { 0 };
    for (const char& c : p)
      pCount[c - 'a']++;
    
    vector<int> result;
    int l = 0;
    for (int r = 0; r < s.length(); r++) {
      sCount[s[r] - 'a']++;
      
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