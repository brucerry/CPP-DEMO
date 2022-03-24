// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <vector>
using namespace std;

// time: average = O(n), worst = O(n^2)
// space: O(log(n))

class Solution {
private:
  int quickSelect(vector<int>& nums, int left, int right, int k) {
    int pivot = nums[right];
    int p = left;

    for (int i = left; i < right; i++) {
      if (nums[i] <= pivot) {
        swap(nums[i], nums[p]);
        p++;
      }
    }
    swap(nums[p], nums[right]);

    if (p > k) return quickSelect(nums, left, p - 1, k);
    else if (p < k) return quickSelect(nums, p + 1, right, k);
    else return nums[p];
  }

public:
  int findKthLargest(vector<int>& nums, int k) {
    k = nums.size() - k;
    return quickSelect(nums, 0, nums.size() - 1, k);
  }
};