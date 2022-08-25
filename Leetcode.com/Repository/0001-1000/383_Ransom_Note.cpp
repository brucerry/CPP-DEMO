// https://leetcode.com/problems/ransom-note/

#include <string>
using namespace std;

// m = len of ransomNote
// n = len of magazine
// time: O(m + n)
// space: O(1)

class Solution {
public:
  bool canConstruct(string& ransomNote, string& magazine) {
    int counts[26] {};
    for (const char& c : magazine)
      counts[c - 'a']++;
    
    for (const char& c : ransomNote) {
      if (counts[c - 'a'] == 0)
        return false;
      counts[c - 'a']--;
    }
    
    return true;
  }
};