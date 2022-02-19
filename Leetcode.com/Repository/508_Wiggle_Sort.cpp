// https://leetcode.com/problems/wiggle-sort/

// https://www.youtube.com/watch?v=vGsyTE4s34w

#include <vector>
#include <iostream>
using namespace std;

// time: O(n)
// space: O(1)
class Solution {
public:
  vector<int> wiggleSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
      if ((i % 2 == 0 && nums[i-1] < nums[i]) || (i % 2 && nums[i-1] > nums[i])) {
        swap(nums[i-1], nums[i]);
      }
    }
    return nums;
  }
};

int main() {
  Solution sol;
  vector<int> nums {45, 2, -34, 21, 444, 33, 33, 232, 335, 2, 34, -33, -445, -1, 0};
  for (auto num : sol.wiggleSort(nums)) {
    cout << num << " ";
  }
}