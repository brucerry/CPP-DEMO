/*
  https://leetcode.com/problems/palindromic-substrings/
*/


#include <string>
#include <iostream>
using namespace std;

// O(n^2) solution
class Solution {
public:
  int countOddLenPalin(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
      int left = i - 1;
      int right = i + 1;
      while (left >= 0 && right < s.length()) {
        if (s[left] == s[right]) {
          count++;
          left--;
          right++;
        }
        else break;
      }
    }
    return count;
  }
  
  int countEvenLenPalin(string s) {
    int count = 0;
    for (int i = 0, j = 1; j < s.length(); i++, j++) {
      if (s[i] == s[j]) {
        count++;
        int left = i - 1;
        int right = j + 1;
        while (left >= 0 && right < s.length()) {
          if (s[left] == s[right]) {
            count++;
            left--;
            right++;
          }
          else break;
        }
      }
    }
    return count;
  }

  int countSubstrings(string s) {
    int count = 0;
    count += countOddLenPalin(s);
    count += countEvenLenPalin(s);
    return count + s.length();
  }
};

// O(n^3) solution
// class Solution {
// public:
//   bool isPalindromic(string s) {
//     for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
//       if (s[i] != s[j]) return false;
//     }
//     return true;
//   }

//   int countSubstrings(string s) {
//     int count = 0;
//     for (int i = 0; i < s.length(); i++) {
//       count++;
//       char currentChar = s[i];
//       int j = i + 1;
//       while (true) {
//         int pos = s.find(currentChar, j);
//         if (pos != string::npos) {
//           string substr = s.substr(i, pos - i + 1);
//           if (isPalindromic(substr)) count++;
//           j = pos + 1;
//         } else {
//           break;
//         }
//       }
//     }
//     return count;
//   }
// };

int main() {
  Solution sol;
  cout << sol.countSubstrings("aaa");
}