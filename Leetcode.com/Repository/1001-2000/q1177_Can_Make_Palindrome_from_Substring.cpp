// https://leetcode.com/problems/can-make-palindrome-from-substring/

#include <string>
#include <vector>
using namespace std;

// n = len of s
// q = size of queries
// time: O(n + q)
// space: O(n)

class Solution {
public:
  vector<bool> canMakePaliQueries(string& s, vector<vector<int>>& queries) {
    int n = s.length();
    vector<int> prefixOddMasks (n + 1);
    for (int i = 1, oddMask = 0; i <= n; i++) {
      prefixOddMasks[i] = oddMask ^= 1 << (s[i-1] - 'a');
    }
    
    int q = queries.size();
    vector<bool> result (q);
    for (int i = 0; i < q; i++) {
      int l = queries[i][0];
      int r = queries[i][1];
      int quota = queries[i][2];
      int oddMask = prefixOddMasks[l] ^ prefixOddMasks[r+1];
      int oddCount = __builtin_popcount(oddMask);
      result[i] = oddCount / 2 <= quota;
    }
    
    return result;
  }
};