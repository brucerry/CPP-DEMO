// https://leetcode.com/problems/permutation-in-string/

#include <string>
#include <array>
using namespace std;

// time: O(s2 + 26) => O(s2)
// space: O(26 * 2) => O(1)
class Optimized {
public:
  bool checkInclusion(string& s1, string& s2) {
    int m = s1.length();
    int n = s2.length();
    
    if (m > n)
      return false;
    
    array<int, 26> s1count { 0 }, s2count { 0 };
    for (int i = 0; i < m; i++) {
      s1count[s1[i] - 'a']++;
      s2count[s2[i] - 'a']++;
    }
    
    int match = 0;
    for (int i = 0; i < 26; i++) {
      if (s1count[i] == s2count[i])
        match++;
    }
    
    if (match == 26)
      return true;
    
    for (int l = 0, r = m; r < n; l++, r++) {
      int r_index = s2[r] - 'a';
      int l_index = s2[l] - 'a';
      
      s2count[r_index]++;      
      if (s2count[r_index] == s1count[r_index])
        match++;
      else if (s2count[r_index] == s1count[r_index] + 1)
        match--;
      
      s2count[l_index]--;
      if (s2count[l_index] == s1count[l_index])
        match++;
      else if (s2count[l_index] == s1count[l_index] - 1)
        match--;
      
      if (match == 26)
        return true;
    }
    
    return false;
  }
};

// time: O(s2 * 26) => O(s2)
// space: O(26 * 2) => O(1)
class ArrayComparison {
public:
  bool checkInclusion(string& s1, string& s2) {
    int m = s1.length();
    int n = s2.length();
    
    if (m > n)
      return false;
    
    array<int, 26> s1count { 0 }, s2count { 0 };
    for (int i = 0; i < m; i++) {
      s1count[s1[i] - 'a']++;
      s2count[s2[i] - 'a']++;
    }
    
    if (s1count == s2count)
      return true;
    
    for (int l = 0, r = m; r < n; l++, r++) {
      s2count[s2[r] - 'a']++;
      s2count[s2[l] - 'a']--;
      
      if (s1count == s2count)
        return true;
    }
    
    return false;
  }
};