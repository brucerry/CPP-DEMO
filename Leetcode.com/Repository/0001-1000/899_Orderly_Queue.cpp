// https://leetcode.com/problems/orderly-queue/

#include <string>
#include <algorithm>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  string orderlyQueue(string s, int k) {
    if (k > 1) {
      sort(s.begin(), s.end());
      return s;
    }
    string result = s;
    for (int i = 1; i < s.size(); i++) {
      result = min(result, s.substr(i) + s.substr(0, i));
    }
    return result;
  }
};