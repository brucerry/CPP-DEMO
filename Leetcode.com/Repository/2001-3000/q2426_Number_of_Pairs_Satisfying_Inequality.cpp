// https://leetcode.com/problems/number-of-pairs-satisfying-inequality/

#include <vector>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
    int n = nums1.size();

    vector<int> nums (n), tmp (n);
    for (int i = 0; i < n; i++) {
      nums[i] = nums1[i] - nums2[i];
    }

    long result = 0;
    mergeSort(nums, tmp, 0, n - 1, diff, result);

    return result;
  }

private:
  void mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r, int diff, long& result) {
    if (l == r)
      return;

    int m = l + (r - l) / 2;
    mergeSort(nums, tmp, l, m, diff, result);
    mergeSort(nums, tmp, m+1, r, diff, result);

    int l_ptr = l, r_ptr = m + 1, ptr = l;
    while (l_ptr <= m and r_ptr <= r) {
      if (nums[l_ptr] <= nums[r_ptr] + diff) {
        result += r - r_ptr + 1;
        l_ptr++;
      }
      else
        r_ptr++;
    }

    l_ptr = l, r_ptr = m + 1, ptr = l;
    while (l_ptr <= m and r_ptr <= r) {
      if (nums[l_ptr] < nums[r_ptr])
        tmp[ptr++] = nums[l_ptr++];
      else
        tmp[ptr++] = nums[r_ptr++];
    }

    while (l_ptr <= m)
      tmp[ptr++] = nums[l_ptr++];
      
    while (r_ptr <= r)
      tmp[ptr++] = nums[r_ptr++];

    for (int i = l; i <= r; i++) {
      nums[i] = tmp[i];
    }
  }
};