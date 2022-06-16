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
    int m = nums1.size();
    int n = nums2.size();
    
    unordered_map<int, int> numIndex; // num, index
    for (int i = 0; i < m; i++)
      numIndex[nums1[i]] = i;
    
    vector<int> result (m);
    vector<int> buffer;
    for (int i = n - 1; i >= 0; i--) {
      int num = nums2[i];
      while (buffer.size() and buffer.back() <= num)
        buffer.pop_back();
      if (numIndex.count(num)) {
        int index = numIndex[num];
        result[index] = buffer.size() ? buffer.back() : -1;
      }
      buffer.emplace_back(num);
    }
    
    return result;
  }
};