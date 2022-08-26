// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int mctFromLeafValues(vector<int>& arr) {
    int result = 0;
    
    vector<int> stack { INT_MAX };
    for (const int& num : arr) {
      while (stack.back() <= num) {
        int mid = stack.back();
        stack.pop_back();
        result += mid * min(stack.back(), num);
      }
      stack.emplace_back(num);
    }
    
    for (int i = 2; i < stack.size(); i++) {
      result += stack[i] * stack[i-1];
    }
    
    return result;
  }
};