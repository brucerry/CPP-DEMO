// https://leetcode.com/problems/merge-sorted-array/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(m + n)
// space: O(1)

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    
    while (j >= 0) {
      if (i < 0 or nums1[i] < nums2[j]) {
        nums1[k--] = nums2[j--];
      }
      else {
        nums1[k--] = nums1[i--];
      }
    }
  }
};