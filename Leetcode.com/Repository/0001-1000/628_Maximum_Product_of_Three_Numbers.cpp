// https://leetcode.com/problems/maximum-product-of-three-numbers/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)
class Solution {
public:
  int maximumProduct(vector<int>& nums) {
    int min1 = INT_MAX, min2 = min1;
    int max1 = INT_MIN, max2 = max1, max3 = max1;
    
    for (const int& num : nums) {
      if (num <= min1) {
        min2 = min1;
        min1 = num;
      }
      else if (num <= min2)
        min2 = num;
      
      if (num >= max1) {
        max3 = max2;
        max2 = max1;
        max1 = num;
      }
      else if (num >= max2) {
        max3 = max2;
        max2 = num;
      }
      else if (num >= max3)
        max3 = num;
    }
    
    return max(min1 * min2 * max1, max1 * max2 * max3);
  }
};

// time: O(n * log(n))
// space: O(log(n)) for sorting
class Sorting {
public:
  int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int product1 = nums[0] * nums[1] * nums.back();
    int product2 = nums.back() * nums[n-2] * nums[n-3];
    return max(product1, product2);
  }
};