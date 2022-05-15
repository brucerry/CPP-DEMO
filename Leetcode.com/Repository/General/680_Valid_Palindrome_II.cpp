// https://leetcode.com/problems/valid-palindrome-ii/

#include <string>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  bool validPalindrome(string& s) {
    for (int l = 0, r = s.length() - 1; l < r; l++, r--) {
      if (s[l] != s[r])
        return isPalin(s, l, r - 1) or isPalin(s, l + 1, r);
    }
    return true;
  }
  
private:
  bool isPalin(string& s, int left, int right) {
    while (left < right) {
      if (s[left] != s[right])
        return false;
      left++;
      right--;
    }
    return true;
  }
};