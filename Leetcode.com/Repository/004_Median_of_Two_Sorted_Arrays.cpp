// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <vector>
using namespace std;

// time: O(log(min(n1, n2)))
// space: O(1)

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) swap(nums1, nums2); // let nums1 always be shorter
    
    int len1 = nums1.size();
    int len2 = nums2.size();
    int totalLen = len1 + len2;
    int half = totalLen / 2;

    int left = 0;
    int right = len1 - 1;

    while (true) {
      int partition1 = floor((left + right) / 2.0);
      int partition2 = half - partition1 - 2; // -2 is because both 'partition1' and 'partition2' are indexed start from 0

      int nums1left = partition1 < 0 ? INT_MIN : nums1[partition1];
      int nums1right = partition1 + 1 >= len1 ? INT_MAX : nums1[partition1 + 1];
      int nums2left = partition2 < 0 ? INT_MIN : nums2[partition2];
      int nums2right = partition2 + 1 >= len2 ? INT_MAX : nums2[partition2 + 1];

      // success partitions
      if (nums1left <= nums2right && nums2left <= nums1right) {
        // odd
        if (totalLen % 2) {
          return min(nums1right, nums2right);
        }
        // even
        return (max(nums1left, nums2left) + min(nums1right, nums2right)) / 2.0;
      }

      else if (nums1left > nums2right) {
        right = partition1 - 1;
      } else {
        left = partition1 + 1;
      }
    }
  }
};