// https://leetcode.com/problems/merge-sorted-array/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  // time: O(m + n)
  // space: O(1)
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int replaceIndex = m + n - 1;
    m--;
    n--;
    while (n >= 0) {
      if (m < 0 || nums2[n] >= nums1[m]) {
        nums1[replaceIndex--] = nums2[n--];
      } else {
        nums1[replaceIndex--] = nums1[m--];
      }
    }
  }

  // time: O(n + m * log(m))
  // space: O(log(m)) to O(m) for sorting
  // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  //   for (int i = 0; i < n; i++) {
  //     nums1[m + i] = nums2[i];
  //   }
  //   sort(nums1.begin(), nums1.end());
  // }
};