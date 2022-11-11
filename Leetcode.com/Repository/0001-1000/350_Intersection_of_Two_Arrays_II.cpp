// https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int counts[1001] {};
    for (const int& n1 : nums1)
      counts[n1]++;
    
    vector<int> result;
    for (const int& n2 : nums2) {
      if (counts[n2]) {
        counts[n2]--;
        result.emplace_back(n2);
      }
    }
    return result;
  }
};