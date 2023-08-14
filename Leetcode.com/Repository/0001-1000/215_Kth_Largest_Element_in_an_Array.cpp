// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// time: O(n * log(k))
// space: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> minheap;
        for (int num : nums) {
            minheap.emplace(num);
            if (minheap.size() > k)
                minheap.pop();
        }
        return minheap.top();
    }
};

// time: average = O(n), worst = O(n^2)
// space: O(log(n))
class QuickSelect {
public:
  int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
  }

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

    if (k < p)
      return quickSelect(nums, left, p - 1, k);
    else if (p < k)
      return quickSelect(nums, p + 1, right, k);
    
    return nums[p];
  }
};

// Quick select with STL
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<>());
        return nums[k-1];
    }
};