// https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int mostFrequent(vector<int>& nums, int key) {
    int counts[1001] {}, result = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i-1] == key and ++counts[nums[i]] > counts[result])
        result = nums[i];
    }
    return result;
  }
};