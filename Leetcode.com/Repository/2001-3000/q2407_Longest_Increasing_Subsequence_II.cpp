// https://leetcode.com/problems/longest-increasing-subsequence-ii/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

struct SegmentTree {
  int n;
  vector<int> tree;
  
  SegmentTree(int _n) : n(_n) {
    tree.resize(_n * 2);
  }
  
  int findMax(int l, int r) {
    l += n;
    r += n;
    int rangeMax = 0;
    while (l < r) {
      if (l & 1)
        rangeMax = max(rangeMax, tree[l++]);
      if (r & 1)
        rangeMax = max(rangeMax, tree[--r]);
      l >>= 1;
      r >>= 1;
    }
    return rangeMax;
  }
  
  void update(int index, int value) {
    index += n;
    tree[index] = value;
    while (index > 1) {
      index >>= 1;
      tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
    }
  }
};

class Solution {
public:
  int lengthOfLIS(vector<int>& nums, int k) {
    int maxValue = *max_element(nums.begin(), nums.end());
    SegmentTree st = SegmentTree(maxValue);
    
    int result = 0;
    for (int num : nums) {
      num--;
      int rangeMax = st.findMax(max(0, num - k), num);
      result = max(result, rangeMax + 1);
      st.update(num, rangeMax + 1);
    }
    
    return result;
  }
};