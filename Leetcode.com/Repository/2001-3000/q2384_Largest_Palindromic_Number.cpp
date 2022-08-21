// https://leetcode.com/problems/largest-palindromic-number/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string largestPalindromic(string& num) {
    int charCount[10] {};
    for (const char& c : num)
      charCount[c - '0']++;
    
    string result;
    for (int i = 9; i >= 0; i--) {
      if (charCount[i] > 1) {
        int prefixUsed = charCount[i] / 2;
        charCount[i] %= 2;
        if (i or result.length())
          result.append(prefixUsed, i + '0');
      }
    }
    
    string rev = result;
    reverse(rev.begin(), rev.end());
    
    for (int i = 9; i >= 0; i--) {
      if (charCount[i]) {
        result += i + '0';
        break;
      }
    }
    
    return result.length() ? result + rev : "0";
  }
};