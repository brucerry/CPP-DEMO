// https://leetcode.com/problems/binary-search/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)
class Iterative {
public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      
      if (nums[m] < target)
        l = m + 1;
      else if (nums[m] > target)
        r = m - 1;
      else
        return m;
    }
    
    return -1;
  }
};

// time: O(log(n))
// space: O(log(n))
class Recursive {
public:
  int search(vector<int>& nums, int target) {
    return solve(nums, target, 0, nums.size() - 1);
  }
  
private:
  int solve(vector<int>& nums, int target, int left, int right) {
    if (left <= right) {
      int mid = left + ((right - left) >> 1);
      
      if (target < nums[mid])
        return solve(nums, target, left, mid - 1);
      else if (target > nums[mid])
        return solve(nums, target, mid + 1, right);
      else
        return mid;
    }
    return -1;
  }
};