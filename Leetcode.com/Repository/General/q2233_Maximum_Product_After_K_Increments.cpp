// https://leetcode.com/problems/maximum-product-after-k-increments/

#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int maximumProduct(vector<int>& nums, int k) {
    if (nums.size() == 1)
      return nums[0] + k;
    
    priority_queue<int, vector<int>, greater<>> minHeap;
    for (const int& num : nums)
      minHeap.emplace(num);
    
    while (k) {
      int smallest = minHeap.top();
      minHeap.pop();
      int diff = min(k, minHeap.top() - smallest + 1);
      smallest += diff;
      k -= diff;
      minHeap.emplace(smallest);
    }
    
    int product = 1;
    while (minHeap.size()) {
      product = (long)product * minHeap.top() % 1000000007;
      minHeap.pop();
    }
    
    return product;
  }
};