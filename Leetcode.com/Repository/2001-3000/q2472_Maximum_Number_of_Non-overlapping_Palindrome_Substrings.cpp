// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/

#include <string>
using namespace std;

// time: O(n * k)
// space: O(1)

class Solution {
public:
  int maxPalindromes(string s, int k) {
    int end = -1, res = 0, n = s.size();
    for (int i = 0; i < n; ) {
      bool found = false;
      for (int l = i, r = i; max(0, end + 1) <= l and r < n; l--, r++) {
        if (s[l] != s[r])
          break;
        if (r - l + 1 >= k) {
          res++;
          end = r;
          found = true;
          break;
        }
      }

      if (found) {
        i = end + 1;
        continue;
      }

      for (int l = i, r = i + 1; max(0, end + 1) <= l and r < n; l--, r++) {
        if (s[l] != s[r])
          break;
        if (r - l + 1 >= k) {
          res++;
          end = r;
          found = true;
          break;
        }
      }

      i = found ? end + 1 : i + 1;
    }
    return res;
  }
};