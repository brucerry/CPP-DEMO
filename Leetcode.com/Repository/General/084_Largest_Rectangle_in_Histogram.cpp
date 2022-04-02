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
    stack<pair<int, int>> stack; // index, height

    for (int i = 0; i < n; i++) {
      int start = i;

      while (stack.size() && heights[i] < stack.top().second) {
        auto& [ index, height ] = stack.top();
        maxArea = max(maxArea, height * (i - index));
        start = index;
        stack.pop();
      }

      stack.push({ start, heights[i] });
    }

    while (stack.size()) {
      auto& [ index, height ] = stack.top();
      maxArea = max(maxArea, height * (n - index));
      stack.pop();
    }

    return maxArea;
  }
};