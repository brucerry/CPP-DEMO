// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minPartitions(string& n) {
    int result = 0;
    for (const char& c : n) {
      result = max(result, c - '0');
    }
    return result;
  }
};