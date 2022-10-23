// https://leetcode.com/problems/set-mismatch/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    int dup = 0, miss = 0;

    for (const int& num : nums) {
      if (nums[abs(num)-1] < 0)
        dup = abs(num);
      else
        nums[abs(num)-1] *= -1;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0)
        miss = i + 1;
    }

    return { dup, miss };
  }
};