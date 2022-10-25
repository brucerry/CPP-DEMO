// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#include <vector>
#include <string>
using namespace std;

// w1 = total chars of w1
// w2 = total chars of w2
// time: O(w1 + w2)
// space: O(1)

class Solution {
public:
  bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
    int w1_len = w1.size(), w2_len = w2.size();
    int i1 = 0, j1 = 0;
    int i2 = 0, j2 = 0;
    while (i1 < w1_len and i2 < w2_len) {
      if (w1[i1][j1] != w2[i2][j2])
        return false;
      if (++j1 == w1[i1].size())
        i1++, j1 = 0;
      if (++j2 == w2[i2].size())
        i2++, j2 = 0;
    }
    return i1 == w1_len and i2 == w2_len;
  }
};