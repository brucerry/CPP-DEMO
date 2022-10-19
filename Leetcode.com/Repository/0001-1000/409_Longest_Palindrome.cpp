// https://leetcode.com/problems/longest-palindrome/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int longestPalindrome(string s) {
    int counts[128] {};
    for (const char& c : s) {
      counts[c]++;
    }

    int result = 0, bonus = 0;
    for (int i = 0; i < 128; i++) {
      if (counts[i] % 2) {
        result += counts[i] - 1;
        bonus = 1;
      }
      else
        result += counts[i];
    }

    return result + bonus;
  }
};