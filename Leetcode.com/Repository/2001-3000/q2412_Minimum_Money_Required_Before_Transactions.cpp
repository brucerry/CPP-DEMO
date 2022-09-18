// https://leetcode.com/problems/minimum-money-required-before-transactions/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  long long minimumMoney(vector<vector<int>>& transactions) {
    long sum_lose = 0;
    int v = 0;
    for (const auto& t : transactions) {
      int cost = t[0], cashback = t[1];
      sum_lose += max(0, cost - cashback);
      v = max(v, min(cost, cashback));
    }
    return sum_lose + v;
  }
};