/*
  https://leetcode.com/problems/minimum-size-subarray-sum/
*/



#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
  int minSubArrayLen(int target, vector<int> nums) {
    int left = 0;
    int sum = 0;
    int result = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      while (sum >= target) {
        result = min(result, i - left + 1);
        sum -= nums[left];
        left++;
      }
    }

    return result == INT_MAX ? 0 : result;
  }
};


int main() {
  Solution sol;
  cout << sol.minSubArrayLen(15, {5,1,3,5,10,7,4,9,2,8}) << endl;
}