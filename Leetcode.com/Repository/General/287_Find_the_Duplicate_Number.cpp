// https://leetcode.com/problems/find-the-duplicate-number/

#include <vector>
using namespace std;

// cycle detection
// time: O(n)
// space: O(1)

class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;

    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    slow = 0;

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};