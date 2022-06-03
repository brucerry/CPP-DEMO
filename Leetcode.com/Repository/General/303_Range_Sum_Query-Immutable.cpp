// https://leetcode.com/problems/range-sum-query-immutable/

#include <vector>
using namespace std;

// time: O(n) for constructor, O(1) for sumRange()
// space: O(n)

class NumArray {
public:
  NumArray(vector<int>& nums) {
    int n = nums.size();
    
    prefixSum = nums;
    for (int i = 1; i < n; i++)
      prefixSum[i] += prefixSum[i-1];
  }
  
  int sumRange(int left, int right) {
    int leftPrefix = left - 1 < 0 ? 0 : prefixSum[left-1];
    return prefixSum[right] - leftPrefix;
  }
  
private:
  vector<int> prefixSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */