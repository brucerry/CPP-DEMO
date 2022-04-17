// https://leetcode.com/problems/house-robber-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int rob(vector<int>& nums) {
    int result1 = houseRobber1(nums, 0, nums.size() - 2);
    int result2 = houseRobber1(nums, 1, nums.size() - 1);
    return max({ result1, result2, nums[0] });
  }
  
private:
  int houseRobber1(vector<int>& nums, int left, int right) {
    int rob1 = 0, rob2 = 0;
    
    for (int i = left; i <= right; i++) {
      int tmp = max(rob2, nums[i] + rob1);
      rob1 = rob2;
      rob2 = tmp;
    }
    
    return rob2;
  }
};