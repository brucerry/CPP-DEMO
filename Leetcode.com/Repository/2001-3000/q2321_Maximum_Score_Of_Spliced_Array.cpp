// https://leetcode.com/problems/maximum-score-of-spliced-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    return max(kadane(nums1, nums2), kadane(nums2, nums1));
  }

private:
  int kadane(vector<int>& a, vector<int>& b) {
    int sum = 0, curSum = 0, result = 0;
    for (int i = 0; i < a.size(); i++) {
      curSum = max(a[i] - b[i], curSum + a[i] - b[i]);
      result = max(result, curSum);
      sum += b[i];
    }
    return sum + result;
  }
};