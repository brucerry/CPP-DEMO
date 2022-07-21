// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <vector>
#include <stack>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    
    stack<pair<int, int>> stack; // height, index
    for (int i = 0; i < n; i++) {
      int index = i;
      while (stack.size() and stack.top().first >= heights[i]) {
        auto [ height, idx ] = stack.top();
        stack.pop();
        maxArea = max(maxArea, height * (i - idx));
        index = idx;
      }
      stack.emplace(heights[i], index);
    }
    
    while (stack.size()) {
      auto [ height, idx ] = stack.top();
      stack.pop();
      maxArea = max(maxArea, height * (n - idx));
    }
    
    return maxArea;
  }
};