// https://leetcode.com/problems/next-greater-element-i/

#include <vector>
#include <unordered_map>
using namespace std;

// m = size of nums1
// n = size of nums2
// time: O(m + n)
// space: O(m + n)

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    
    unordered_map<int, int> n2Greater; // n2 value, next greater
    vector<int> result (len1, -1), stack;
    
    for (const int& n2 : nums2) {
      while (stack.size() and stack.back() < n2) {
        n2Greater[stack.back()] = n2;
        stack.pop_back();
      }
      stack.emplace_back(n2);
    }
    
    for (int i = 0; i < len1; i++) {
      if (n2Greater.count(nums1[i]))
        result[i] = n2Greater[nums1[i]];
    }
    
    return result;
  }
};