// https://leetcode.com/problems/valid-anagram/

#include <string>
#include <array>
using namespace std;

// time: O(n)
// space: O(26) => O(1)
class Array {
public:
  bool isAnagram(string& s, string& t) {
    if (s.length() != t.length())
      return false;
    
    array<int, 26> sCount { 0 }, tCount { 0 };
    for (int i = 0; i < s.length(); i++) {
      sCount[s[i] - 'a']++;
      tCount[t[i] - 'a']++;
    }
    
    return sCount == tCount;
  }
};