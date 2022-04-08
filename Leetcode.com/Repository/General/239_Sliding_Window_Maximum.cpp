// https://leetcode.com/problems/sliding-window-maximum/

#include <vector>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> deque; // monotonic decreasing queue, store indices

    int l = 0, r = 0;

    while (r < nums.size()) {
      // remove smaller values from the back
      while (deque.size() && nums[r] > nums[deque.back()])
        deque.pop_back();

      deque.emplace_back(r);

      // pop front if window left is out-of-bound
      if (l > deque.front())
        deque.pop_front();

      // update when window size is k
      if (r - l + 1 == k) {
        ans.emplace_back(nums[deque.front()]);
        l++;
      }

      r++;
    }

    return ans;
  }
};