// https://leetcode.com/problems/maximum-tastiness-of-candy-basket/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(max(price)))
// space: O(log(n)) for sorting

class Solution {
public:
  int maximumTastiness(vector<int>& price, int k) {
    sort(price.begin(), price.end());
    int l = 0, r = price.back() - price.front();
    while (l < r) {
      int m = l + (r - l + 1) / 2;
      if (check(price, k, m))
        l = m;
      else
        r = m - 1;
    }
    return l;
  }

private:
  bool check(vector<int>& price, int k, int diff) {
    int count = 1;
    for (int l = 0, r = 1; r < price.size(); r++) {
      if (price[r] - price[l] >= diff) {
        l = r;
        count++;
      }
    }
    return count >= k;
  }
};