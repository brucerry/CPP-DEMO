// https://leetcode.com/problems/remove-palindromic-subsequences/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int removePalindromeSub(string& s) {
    return 2 - equal(s.begin(), s.end(), s.rbegin());
  }
};