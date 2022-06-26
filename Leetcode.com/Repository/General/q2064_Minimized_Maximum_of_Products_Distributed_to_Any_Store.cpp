// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

#include <vector>
using namespace std;

// q = size of quantities
// time: O(q * log(max(quantities)))
// space: O(1)

class Solution {
public:
  int minimizedMaximum(int n, vector<int>& quantities) {
    int l = 1, r = 0;
    for (const int& qty : quantities)
      r = max(r, qty);
    
    while (l < r) {
      int m = l + ((r - l) >> 1);
      if (canDistribute(n, quantities, m))
        r = m;
      else
        l = m + 1;
    }
    return r;
  }
  
private:
  bool canDistribute(int n, vector<int>& quantities, int maxQty) {
    int store = 0;
    for (const int& qty : quantities) {
      store += qty / maxQty;
      if (qty % maxQty)
        store++;
    }
    return store <= n;
  }
};