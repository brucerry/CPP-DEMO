// https://leetcode.com/problems/majority-element/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int count = 0, result = 0;
    
    for (const int& num : nums) {
      if (count == 0)
        result = num;
      count += num == result ? 1 : -1;
    }
    
    return result;
  }
};