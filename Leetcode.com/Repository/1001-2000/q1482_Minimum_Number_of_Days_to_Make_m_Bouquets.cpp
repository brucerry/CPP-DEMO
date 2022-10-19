// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <vector>
#include <algorithm>
using namespace std;

// max = max of bloomDay
// time: O(n * log(max))
// space: O(1)

class Solution {
public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    if (bloomDay.size() < (long)m * k)
      return -1;

    auto [ minit, maxit ] = minmax_element(bloomDay.begin(), bloomDay.end());
    int l = *minit, r = *maxit;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (canMake(bloomDay, m, k, mid))
        r = mid;
      else
        l = mid + 1;
    }
    return r;
  }

private:
  bool canMake(vector<int>& bloomDay, int need_bouquets, int adj_len, int waitDays) {
    int made = 0, consecutive_len = 0;
    for (const int& bd : bloomDay) {
      if (bd <= waitDays) {
        consecutive_len++;
        if (consecutive_len == adj_len) {
          made++;
          consecutive_len = 0;
        }
      }
      else
        consecutive_len = 0;
    }
    return made >= need_bouquets;
  }
};