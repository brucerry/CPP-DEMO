// https://leetcode.com/problems/powerful-integers/

#include <vector>
#include <unordered_set>
using namespace std;

// m = log(bound) base x
// n = log(bound) base y
// time: O(m * n)
// space: O(m * n)

class Solution {
public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> powerfuls;
    for (int xx = 1; xx <= bound; xx *= x) {
      for (int yy = 1; xx + yy <= bound; yy *= y) {
        powerfuls.insert(xx + yy);
        if (y == 1)
          break;
      }
      if (x == 1)
        break;
    }
    return vector<int>(powerfuls.begin(), powerfuls.end());
  }
};