// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    
    int swap = 1, stay = 0;
    for (int i = 1; i < nums1.size(); i++) {
      int curSwap = n, curStay = n;
      if (nums1[i-1] < nums1[i] and nums2[i-1] < nums2[i]) {
        curSwap = swap + 1;
        curStay = stay;
      }
      if (nums1[i-1] < nums2[i] and nums2[i-1] < nums1[i]) {
        curSwap = min(curSwap, stay + 1);
        curStay = min(curStay, swap);
      }
      stay = curStay;
      swap = curSwap;
    }
    
    return min(swap, stay);
  }
};