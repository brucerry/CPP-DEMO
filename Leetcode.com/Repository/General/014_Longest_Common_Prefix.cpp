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
    string commonPrefix;
    
    for (int i = 0; i < strs[0].length(); i++) {
      for (const string& s : strs) {
        if (i == s.length() or s[i] != strs[0][i])
          return commonPrefix;
      }
      commonPrefix += strs[0][i];
    }
    
    return commonPrefix;
  }
};