// https://leetcode.com/problems/permutation-in-string/

#include <string>
#include <array>
using namespace std;

// time: O(s2)
// space: O(1)

class Solution {
public:
  bool checkInclusion(string& s1, string& s2) {
    int m = s1.length();
    int n = s2.length();
    
    if (m > n)
      return false;
    
    array<int, 26> s1Count { 0 }, s2Count { 0 };
    for (int i = 0; i < m; i++) {
      s1Count[s1[i] - 'a']++;
      s2Count[s2[i] - 'a']++;
    }
    
    int match = 0;
    for (int i = 0; i < 26; i++) {
      if (s1Count[i] == s2Count[i])
        match++;
    }
    
    if (match == 26)
      return true;
    
    for (int l = 0, r = m; r < n; l++, r++) {      
      int l_index = s2[l] - 'a';
      int r_index = s2[r] - 'a';
      
      s2Count[r_index]++;
      if (s1Count[r_index] == s2Count[r_index])
        match++;
      else if (s1Count[r_index] + 1 == s2Count[r_index])
        match--;
      
      s2Count[l_index]--;
      if (s1Count[l_index] == s2Count[l_index])
        match++;
      else if (s1Count[l_index] - 1 == s2Count[l_index])
        match--;
      
      if (match == 26)
        return true;
    }
    
    return false;
  }
};