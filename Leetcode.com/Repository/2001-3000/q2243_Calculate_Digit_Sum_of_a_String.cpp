// https://leetcode.com/problems/calculate-digit-sum-of-a-string/

#include <string>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  string digitSum(string s, int k) {
    while (s.size() > k) {
      string new_s;
      for (int i = 0; i < s.size(); i += k) {
        int sum = 0;
        for (int j = i; j < min(i + k, (int)s.size()); j++) {
          sum += s[j] - '0';
        }
        new_s += to_string(sum);
      }
      s = new_s;
    }
    return s;
  }
};