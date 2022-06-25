// https://leetcode.com/problems/steps-to-make-array-non-decreasing/

#include <vector>
#include <stack>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int totalSteps(vector<int>& nums) {
    stack<pair<int, int>> stack; // num, step
    int result = 0;
    
    for (const int& num : nums) {
      int step = 0;
      while (stack.size() and stack.top().first <= num) {
        step = max(step, stack.top().second);
        stack.pop();
      }
      step = stack.size() ? step + 1 : 0;
      stack.emplace(num, step);
      result = max(result, step);
    }
    
    return result;
  }
};