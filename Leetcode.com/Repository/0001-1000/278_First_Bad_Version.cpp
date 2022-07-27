// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int firstBadVersion(int n) {
    int l = 1, r = n;
    while (l < r) {
      int m = l + ((r - l) >> 1);
      if (isBadVersion(m))
        r = m;
      else
        l = m + 1;
    }
    return r;
  }
};