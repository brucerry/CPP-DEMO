// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int specialArray(vector<int>& nums) {
    int numCount[1001] {};
    for (const int& num : nums) {
      numCount[num]++;
    }
    
    for (int num = 999; num >= 0; num--) {
      numCount[num] += numCount[num+1];
      if (num == numCount[num])
        return num;
    }
    
    return -1;
  }
};