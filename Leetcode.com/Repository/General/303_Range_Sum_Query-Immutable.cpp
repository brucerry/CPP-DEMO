// https://leetcode.com/problems/range-sum-query-immutable/

#include <vector>
using namespace std;

// time: O(n) for constructor, O(1) for sumRange()
// space: O(n)

class NumArray {
public:
  NumArray(vector<int>& nums) {
    prefix = nums;
    for (int i = 1; i < nums.size(); i++) {
      prefix[i] += prefix[i-1];
    }
  }
  
  int sumRange(int left, int right) {
    return prefix[right] - (left - 1 < 0 ? 0 : prefix[left-1]);
  }
  
private:
  vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */