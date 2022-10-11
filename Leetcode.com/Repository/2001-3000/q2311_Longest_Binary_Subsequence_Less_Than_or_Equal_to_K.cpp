// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/

#include <string>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int longestSubsequence(string& s, int k) {
    int numberOfOnes = 0, sum = 0, pow = 1;
    for (int i = s.size() - 1; i >= 0 and sum + pow <= k; i--) {
      if (s[i] == '1') {
        numberOfOnes++;
        sum += pow;
      }
      pow <<= 1;
    }
    return numberOfOnes + count(s.begin(), s.end(), '0');
  }
};