// https://leetcode.com/problems/first-unique-character-in-a-string/

#include <array>
#include <string>
using namespace std;

// time: O(n)
// space: O(26) => O(1)

class Solution {
public:
  int firstUniqChar(string& s) {
    array<int, 26> charCount { 0 };
    for (const char& c : s)
      charCount[c - 'a']++;
    
    for (int i = 0; i < s.length(); i++) {
      if (charCount[s[i] - 'a'] == 1)
        return i;
    }
    return -1;
  }
};