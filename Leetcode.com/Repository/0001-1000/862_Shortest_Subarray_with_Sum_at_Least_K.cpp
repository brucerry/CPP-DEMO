// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

#include <vector>
#include <deque>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long> prefixSum (n + 1);
    for (int i = 1; i <= n; i++)
      prefixSum[i] = prefixSum[i-1] + nums[i-1];
    
    deque<int> deque; // index
    int len = n + 1;
    for (int i = 0; i <= n; i++) {
      while (deque.size() and prefixSum[i] - prefixSum[deque.front()] >= k) {
        len = min(len, i - deque.front());
        deque.pop_front();
      }
      
      while (deque.size() and prefixSum[deque.back()] >= prefixSum[i])
        deque.pop_back();
      
      deque.emplace_back(i);
    }
    
    return len <= n ? len : -1;
  }
};