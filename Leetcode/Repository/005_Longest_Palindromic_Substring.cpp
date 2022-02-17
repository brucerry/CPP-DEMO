// https://leetcode.com/problems/longest-palindromic-substring/


#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // time: O(n^2) solution
  string longestPalindrome(string s) {
    int maxLen = 0, maxLeft = 0;
    int left, right;

    for (int i = 0; i < s.length(); i++) {
      // odd length
      left = i;
      right = i;
      while (left >= 0 && right < s.length() && s[left] == s[right]) {
        int len = right - left + 1;
        if (maxLen < len) {
          maxLen = len;
          maxLeft = left;
        }
        left--;
        right++;
      }

      // even length
      left = i;
      right = i + 1;
      while (left >= 0 && right < s.length() && s[left] == s[right]) {
        int len = right - left + 1;
        if (maxLen < len) {
          maxLen = len;
          maxLeft = left;
        }
        left--;
        right++;
      } 
    }

    return s.substr(maxLeft, maxLen);
  }

  // time: O(n^3) solution
  // bool isPalindrome(string s) {
  //   for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
  //     if (s[i] != s[j]) return false;
  //   }
  //   return true;
  // }

  // string longestPalindrome(string s, int head, int tail, unordered_map<string, string> &memo) {
  //   string pos = to_string(head) + ',' + to_string(tail);
  //   if (memo.count(pos)) return memo[pos];
  //   if (head == tail) return string(1, s[head]);

  //   if (s[head] == s[tail]) {
  //     string substr = s.substr(head, tail - head + 1);
  //     if (isPalindrome(substr)) {
  //       memo[pos] = substr;
  //       return substr;
  //     }
  //   }
    
  //   string dropHeadStr = longestPalindrome(s, head + 1, tail, memo);
  //   string dropTailStr = longestPalindrome(s, head, tail - 1, memo);
  //   if (dropHeadStr.length() > dropTailStr.length()) memo[pos] = dropHeadStr;
  //   else memo[pos] = dropTailStr;

  //   return memo[pos];
  // }

  // string longestPalindrome(string s) {
  //   unordered_map<string, string> memo;
  //   return longestPalindrome(s, 0, s.length() - 1, memo);
  // }
};