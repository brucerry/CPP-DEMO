// https://leetcode.com/problems/string-compression-ii/

#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
  int getLengthOfOptimalCompression(string s, int k) {
    int memo[100][101];
    memset(memo, -1, sizeof(memo));
    return solve(s, k, memo, 0);
  }

private:
  int solve(string& s, int k, int (*memo)[101], int start) {
    if (k < 0)
      return 1000;

    int n = s.size();
    if (start == n or k >= n - start)
      return 0;

    int& result = memo[start][k];
    if (result != -1)
      return result;

    result = 1000;
    int counts[26] {}, most = 0;
    for (int i = start; i < n; i++) {
      most = max(most, ++counts[s[i] - 'a']);
      int remain = i - start + 1 - most;
      result = min(result, 1 + len(most) + solve(s, k - remain, memo, i + 1));
    }

    return result;
  }

  int len(int n) {
    return n == 1 ? 0 : n < 10 ? 1 : n < 100 ? 2 : 3;
  }
};