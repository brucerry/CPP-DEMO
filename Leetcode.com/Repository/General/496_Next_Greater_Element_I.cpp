// https://leetcode.com/problems/next-greater-element-i/

#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// m = size of nums1
// n = size of nums2
// time: O(m + n)
// space: O(m + n)

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> numIndex;
    for (int i = 0; i < nums1.size(); i++)
      numIndex[nums1[i]] = i;
    
    stack<int> stack;
    vector<int> ans (nums1.size());
    for (int i = nums2.size() - 1; i >= 0; i--) {
      while (stack.size() and nums2[i] > stack.top())
        stack.pop();
      if (numIndex.count(nums2[i])) {
        int idx = numIndex[nums2[i]];
        ans[idx] = stack.size() ? stack.top() : -1;
      }
      stack.emplace(nums2[i]);
    }
          
    return ans;
  }
};