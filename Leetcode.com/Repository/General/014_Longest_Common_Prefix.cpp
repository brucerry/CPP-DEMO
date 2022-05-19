// https://leetcode.com/problems/longest-common-prefix/

#include <string>
#include <vector>
using namespace std;

// n = len of strs
// m = min len of elements in strs
// time: O(n * m)
// space: O(1)

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string lcp;
    
    for (int i = 0; i < strs[0].size(); i++) {
      for (const string& s : strs) {
        if (i == s.length() or strs[0][i] != s[i])
          return lcp;
      }
      lcp += strs[0][i];
    }
    
    return lcp;
  }
};