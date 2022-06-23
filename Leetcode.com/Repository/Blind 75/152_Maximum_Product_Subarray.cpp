// https://leetcode.com/problems/maximum-product-subarray/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int curMin = 1, curMax = 1;
    int product = nums[0];
    for (const int& num : nums) {
      int tmpMin = curMin * num;
      int tmpMax = curMax * num;
      
      curMin = min({ tmpMin, tmpMax, num });
      curMax = max({ tmpMin, tmpMax, num });
      product = max(product, curMax);
    }
    return product;
  }
};