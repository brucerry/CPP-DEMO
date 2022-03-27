// https://leetcode.com/problems/distinct-subsequences/

#include <string>
#include <vector>
using namespace std;

// time: O(s * t)
// space: O(t)

class Solution {
public:
  int numDistinct(string s, string t) {
    vector<unsigned int> dp (t.length() + 1, 0);
    dp.back() = 1;

    for (int i = s.length() - 1; i >= 0; i--) {
      for (int j = 0; j < t.length(); j++) {
        if (s[i] == t[j]) {
          dp[j] += dp[j+1];
        }
      }
    }

    return dp[0];
  }
};