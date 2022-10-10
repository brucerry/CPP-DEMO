// https://leetcode.com/problems/break-a-palindrome/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string breakPalindrome(string& palindrome) {
    int n = palindrome.size();
    for (int i = 0; i < n / 2; i++) {
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;
      }
    }
    palindrome.back()++;
    return n == 1 ? "" : palindrome;
  }
};