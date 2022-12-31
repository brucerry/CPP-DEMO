// https://leetcode.com/problems/lemonade-change/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (const int& bill : bills) {
      int change = bill - 5;
      if (change == 0)
        five++;
      else if (change == 5)
        five--, ten++;
      else if (ten)
        five--, ten--;
      else
        five -= 3;
      if (five < 0)
        return false;
    }
    return true;
  }
};