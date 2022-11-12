// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
      int bit1 = __builtin_popcount(a), bit2 = __builtin_popcount(b);
      return bit1 == bit2 ? a < b : bit1 < bit2;
    });
    return arr;
  }
};