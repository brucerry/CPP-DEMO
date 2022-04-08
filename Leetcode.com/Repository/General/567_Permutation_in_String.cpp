// https://leetcode.com/problems/permutation-in-string/

#include <string>
#include <array>
using namespace std;

// time: O(s2)
// space: O(1)

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length())
      return false;
    
    array<int, 26> charCountS1 { 0 }, charCountS2 { 0 };
    
    for (int i = 0; i < s1.length(); i++) {
      charCountS1[s1[i] - 'a']++;
      charCountS2[s2[i] - 'a']++;
    }
    
    int matches = 0;
    
    for (int i = 0; i < 26; i++) {
      if (charCountS1[i] == charCountS2[i])
        matches++;
    }
    
    int l = 0;
    
    for (int r = s1.length(); r < s2.length(); r++) {
      if (matches == 26)
        return true;
      
      int l_index = s2[l] - 'a';
      int r_index = s2[r] - 'a';
      
      charCountS2[r_index]++;
      
      if (charCountS1[r_index] == charCountS2[r_index])
        matches++;
      else if (charCountS1[r_index] + 1 == charCountS2[r_index])
        matches--;
      
      charCountS2[l_index]--;
      
      if (charCountS1[l_index] == charCountS2[l_index])
        matches++;
      else if (charCountS1[l_index] - 1 == charCountS2[l_index])
        matches--;
      
      l++;
    }
    
    return matches == 26;
  }
};