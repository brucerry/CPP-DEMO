// https://leetcode.com/problems/house-robber/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class TwoVariables {
public:
  int rob(vector<int>& nums) {
    int one = 0, two = 0;
    
    for (const int& num : nums) {
      int tmp = max(num + one, two);
      one = two;
      two = tmp;
    }
    
    return two;
  }
};

class InPlace {
public:
  int rob(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
      int val = i - 2 < 0 ? 0 : nums[i-2];
      nums[i] = max(nums[i] + val, nums[i-1]);
    }
    return nums.back();
  }
};