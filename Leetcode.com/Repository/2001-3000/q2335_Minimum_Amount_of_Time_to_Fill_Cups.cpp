// https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/

#include <vector>
using namespace std;

// time: O(n) [O(1) specified for this question]
// space: O(1)

class Solution {
public:
  int fillCups(vector<int>& amount) {
    int largest = 0, sum = 0;
    for (const int& amt : amount) {
      largest = max(largest, amt);
      sum += amt;
    }
    return max(largest, (sum + 1) / 2);
  }
};