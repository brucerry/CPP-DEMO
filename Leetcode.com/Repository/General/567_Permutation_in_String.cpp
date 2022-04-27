// https://leetcode.com/problems/permutation-in-string/

#include <string>
#include <array>
using namespace std;

// time: O(s2)
// space: O(1)

class Solution {
public:
  bool checkInclusion(string& s1, string& s2) {
    if (s1.length() > s2.length())
      return false;
    
    array<int, 26> s1Count { 0 }, s2Count { 0 };
    
    for (int i = 0; i < s1.length(); i++) {
      s1Count[s1[i] - 'a']++;
      s2Count[s2[i] - 'a']++;
    }
    
    int matches = 0;
    
    for (int i = 0; i < 26; i++) {
      if (s1Count[i] == s2Count[i])
        matches++;
    }
    
    if (matches == 26)
      return true;
    
    int l = 0;
    
    for (int r = s1.length(); r < s2.length(); r++) {      
      int l_index = s2[l] - 'a';
      int r_index = s2[r] - 'a';
      
      s2Count[r_index]++;
      
      if (s1Count[r_index] == s2Count[r_index])
        matches++;
      else if (s1Count[r_index] + 1 == s2Count[r_index])
        matches--;
      
      s2Count[l_index]--;
      
      if (s1Count[l_index] == s2Count[l_index])
        matches++;
      else if (s1Count[l_index] - 1 == s2Count[l_index])
        matches--;
      
      if (matches == 26)
        return true;
      
      l++;
    }
    
    return false;
  }
};