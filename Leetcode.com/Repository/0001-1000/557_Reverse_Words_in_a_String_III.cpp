// https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <string>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string reverseWords(string& s) {
    for (int i = 0; i < s.length(); i++) {
      int end = s.find(' ', i);
      if (end != string::npos) {
        reverse(s.begin() + i, s.begin() + end);
        i = end;
      }
      else {
        reverse(s.begin() + i, s.end());
        break;
      }
    }
    return s;
  }
};