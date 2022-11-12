// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

#include <vector>
using namespace std;

// time: O(n + m)
// space: O(1)

class Solution {
public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int result = 0;
    for (int i = 0, j = 0; i < nums1.size() and j < nums2.size(); ) {
      if (nums1[i] > nums2[j])
        i++;
      else
        result = max(result, j++ - i);
    }
    return result;
  }
};