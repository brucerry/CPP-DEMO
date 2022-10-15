// https://leetcode.com/problems/range-product-queries-of-powers/

#include <vector>
using namespace std;

// q = size of queries
// time: O(q ∗ log(n))
// space: O(log(n))

class Solution {
public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers;
    for (int i = 0; i < 30; i++) {
      if (n & (1 << i))
        powers.emplace_back(1 << i);
    }
    
    vector<int> result;
    for (const auto& quer : queries) {
      int l = quer[0], r = quer[1];
      long product = 1;
      for (int i = l; i <= r; i++) {
        product = product * powers[i] % 1000000007;
      }
      result.emplace_back(product);
    }
    return result;
  }
};