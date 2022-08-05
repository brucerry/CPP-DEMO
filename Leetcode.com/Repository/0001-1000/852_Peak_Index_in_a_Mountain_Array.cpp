// https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int l = 0, r = arr.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (arr[m] > arr[m+1])
        r = m;
      else
        l = m + 1;
    }
    return r;
  }
};