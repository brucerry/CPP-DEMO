// https://leetcode.com/problems/range-sum-query-mutable/

#include <vector>
using namespace std;

// time: O(n) for constructor, O(log(n)) for update() and sumRange()
// space: O(n)

class NumArray {
public:
  NumArray(vector<int>& nums) : n(nums.size()) {
    segmentTree.resize(n);
    segmentTree.insert(segmentTree.end(), nums.begin(), nums.end());
    for (int i = n - 1; i; i--)
      segmentTree[i] = segmentTree[i << 1] + segmentTree[(i << 1) + 1];
  }
  
  void update(int index, int val) {
    index += n;
    segmentTree[index] = val;
    while (index) {
      int l = index, r = index;
      if (index & 1)
        l = index - 1;
      else
        r = index + 1;
      segmentTree[index >> 1] = segmentTree[l] + segmentTree[r];
      index >>= 1;
    }
  }
  
  int sumRange(int left, int right) {
    left += n;
    right += n;
    int sum = 0;
    while (left <= right) {
      if (left & 1)
        sum += segmentTree[left++];
      if ((right & 1) == 0)
        sum += segmentTree[right--];
      left >>= 1;
      right >>= 1;
    }
    return sum;
  }
  
private:
  int n;
  vector<int> segmentTree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */