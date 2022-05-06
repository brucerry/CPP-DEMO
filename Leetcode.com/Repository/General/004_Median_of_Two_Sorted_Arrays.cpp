// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <vector>
using namespace std;

// time: O(log(min(n1, n2)))
// space: O(1)

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // let nums1 length always be shorter
    if (nums1.size() > nums2.size())
      nums1.swap(nums2);
    
    int totalLen = nums1.size() + nums2.size();
    int halfLen = totalLen >> 1;
    int l = 0, r = nums1.size() - 1;
    
    while (true) {
      int m1 = l + ((r - l) >> 1);
      int m2 = halfLen - m1 - 2; // -2 is because both 'm1' and 'm2' are indexed start from 0
      
      int leftVal1 = m1 < 0 ? INT_MIN : nums1[m1];
      int rightVal1 = m1 + 1 >= nums1.size() ? INT_MAX : nums1[m1+1];
      int leftVal2 = m2 < 0 ? INT_MIN : nums2[m2];
      int rightVal2 = m2 + 1 >= nums2.size() ? INT_MAX : nums2[m2+1];
      
      if (leftVal1 <= rightVal2 and leftVal2 <= rightVal1) {
        // odd len
        if (totalLen & 1)
          return min(rightVal1, rightVal2);
        
        // even len
        return (max(leftVal1, leftVal2) + min(rightVal1, rightVal2)) / 2.0;
      }
      
      // leftVal1 is too large
      else if (leftVal1 > rightVal2)
        r = m1 - 1;
      
      // rightVal1 is too small
      else
        l = m1 + 1;
    }
  }
};