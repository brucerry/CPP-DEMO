// https://leetcode.com/problems/count-palindromic-subsequences/

#include <string>
#include <cstring>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int countPalindromes(string s) {
    int mod = 1e9 + 7, n = s.size();
    long pre[10000][10][10] {}, suf[10000][10][10] {}, counts[10] {};

    for (int i = 0; i < n; i++) {
      int d = s[i] - '0';
      if (i) {
        for (int p1 = 0; p1 < 10; p1++) {
          for (int p2 = 0; p2 < 10; p2++) {
            pre[i][p1][p2] = pre[i-1][p1][p2] + (d == p2 ? counts[p1] : 0);
          }
        }
      }
      counts[d]++;
    }

    memset(counts, 0, sizeof(counts));

    for (int i = n - 1; i >= 0; i--) {
      int d = s[i] - '0';
      if (i + 1 < n) {
        for (int s1 = 0; s1 < 10; s1++) {
          for (int s2 = 0; s2 < 10; s2++) {
            suf[i][s1][s2] = suf[i+1][s1][s2] + (d == s1 ? counts[s2] : 0);
          }
        }
      }
      counts[d]++;
    }

    int res = 0;
    for (int i = 1; i < n - 1; i++) {
      for (int d1 = 0; d1 < 10; d1++) {
        for (int d2 = 0; d2 < 10; d2++) {
          res = (res + pre[i-1][d1][d2] * suf[i+1][d2][d1]) % mod;
        }
      }
    }

    return res;
  }
};