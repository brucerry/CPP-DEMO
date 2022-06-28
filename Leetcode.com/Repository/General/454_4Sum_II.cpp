// https://leetcode.com/problems/4sum-ii/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> prefixCount; // prefix sum, count
    for (const int& n1 : nums1) {
      for (const int& n2 : nums2) {
        prefixCount[n1 + n2]++;
      }
    }
    
    int count = 0;
    for (const int& n3 : nums3) {
      for (const int& n4 : nums4) {
        if (prefixCount.count(0 - n3 - n4))
          count += prefixCount[0 - n3 - n4];
      }
    }
    
    return count;
  }
};