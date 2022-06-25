// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size();
    
    int r = n - 1;
    while (r) {
      if (arr[r-1] > arr[r])
        break;
      r--;
    }
    
    if (r == 0)
      return 0;
    
    int len = r;
    for (int l = 0; l < n; l++) {
      if (l and arr[l-1] > arr[l])
        break;
      while (r < n and arr[l] > arr[r])
        r++;
      len = min(len, r - l - 1);
    }
    
    return len;
  }
};