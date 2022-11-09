// https://leetcode.com/problems/merge-strings-alternately/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string mergeAlternately(string w1, string w2) {
    int n = w1.size(), m = w2.size();
    string result;
    for (int i = 0; i < max(n, m); i++) {
      if (i < n)
        result += w1[i];
      if (i < m)
        result += w2[i];
    }
    return result;
  }
};