// https://leetcode.com/problems/sliding-window-maximum/

#include <vector>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> deque; // monotonic decreasing queue, store indices
    
    vector<int> window;
    int l = 0;
    for (int r = 0; r < n; r++) {
      // remove smaller values from the back
      while (deque.size() and nums[deque.back()] <= nums[r])
        deque.pop_back();
      
      deque.emplace_back(r);
      
      // pop front if index is out of (window's left) bound 
      if (deque.front() < l)
        deque.pop_front();
      
      // update result when window size is k
      if (r - l + 1 == k) {
        window.emplace_back(nums[deque.front()]);
        l++;
      }
    }
    
    return window;
  }
};