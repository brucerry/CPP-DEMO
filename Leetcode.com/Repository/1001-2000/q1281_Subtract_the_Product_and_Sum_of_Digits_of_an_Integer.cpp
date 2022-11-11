// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int subtractProductAndSum(int n) {
    int product = 1, sum = 0;
    for (; n; n /= 10) {
      product *= n % 10;
      sum += n % 10;
    }
    return product - sum;
  }
};