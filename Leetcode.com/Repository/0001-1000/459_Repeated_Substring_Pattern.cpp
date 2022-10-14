// https://leetcode.com/problems/repeated-substring-pattern/

#include <string>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool repeatedSubstringPattern(string& s) {
    return (s + s).substr(1, s.size() * 2 - 2).find(s) != string::npos;
  }
};