// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <vector>
#include <stack>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    stack<pair<int, int>> stack; // height, index
    const int n = heights.size();
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
      int index = i;
      
      while (stack.size() && stack.top().first >= heights[i]) {
        const auto& [ height, idx ] = stack.top();
        ans = max(ans, (i - idx) * height);
        index = idx;
        stack.pop();
      }
      
      stack.emplace(heights[i], index);
    }
    
    while (stack.size()) {
      const auto& [ height, idx ] = stack.top();
      ans = max(ans, (n - idx) * height);
      stack.pop();
    }
    
    return ans;
  }
};