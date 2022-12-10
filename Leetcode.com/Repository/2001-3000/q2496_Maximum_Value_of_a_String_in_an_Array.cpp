// https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/

#include <vector>
#include <string>
using namespace std;

// n = size of strs
// s = len of strs[i]
// time: O(n * s)
// space: O(1)

class Solution {
public:
  int maximumValue(vector<string>& strs) {
    int res = 0;
    for (const string& s : strs) {
      bool isNum = true;
      for (const char& c : s) {
        if (!isdigit(c))
          isNum = false;
      }
      if (isNum)
        res = max(res, stoi(s));
      else
        res = max(res, (int)s.size());
    }
    return res;
  }
};