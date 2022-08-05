// https://leetcode.com/problems/find-in-mountain-array/


// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length(), l, r, m, peakIndex = 0;
    
    l = 0, r = n - 1;
    while (l < r) {
      m = l + (r - l) / 2;
      if (mountainArr.get(m) > mountainArr.get(m + 1))
        r = peakIndex = m;
      else
        l = m + 1;
    }
    
    l = 0, r = peakIndex;
    while (l <= r) {
      m = l + (r - l) / 2;
      if (mountainArr.get(m) < target)
        l = m + 1;
      else if (mountainArr.get(m) > target)
        r = m - 1;
      else
        return m;
    }
    
    l = peakIndex, r = n - 1;
    while (l <= r) {
      m = l + (r - l) / 2;
      if (mountainArr.get(m) < target)
        r = m - 1;
      else if (mountainArr.get(m) > target)
        l = m + 1;
      else
        return m;
    }
    
    return -1;
  }
};