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
  int houseRobber1(vector<int>& nums, int l, int r) {
    int one = 0, two = 0;
    
    for (int i = l; i <= r; i++) {
      int tmp = max(nums[i] + one, two);
      one = two;
      two = tmp;
    }
    
    return two;
  }
};