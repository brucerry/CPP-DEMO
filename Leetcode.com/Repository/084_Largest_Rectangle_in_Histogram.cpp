/*
  https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int largestRectangleArea(vector<int> heights) {
    int wholeLength = heights.size();
    int maxArea = 0;
    stack<tuple<int, int>> stack;

    for (int i = 0; i < wholeLength; i++) {
      int currentIndex = i, currentHeight = heights[i];
      if (i == 0) {
        stack.push({currentIndex, currentHeight});
      } else {
        auto [ topIndex, topHeight ] = stack.top();
        if (currentHeight <= topHeight) {
          while (currentHeight <= topHeight) {
            topIndex = get<0>(stack.top());
            int topArea = topHeight * (currentIndex - topIndex);
            maxArea = max(maxArea, topArea);
            stack.pop();
            if (stack.size()) {
              topHeight = get<1>(stack.top());
            } else {
              break;
            }
          }
          stack.push({topIndex, currentHeight});
        } else {
          stack.push({currentIndex, currentHeight});
        }
      }
    }

    while (stack.size()) {
      auto [ topIndex, topHeight ] = stack.top();
      stack.pop();
      int topArea = topHeight * (wholeLength - topIndex);
      maxArea = max(maxArea, topArea);
    }

    return maxArea;
  }
};

int main() {
  Solution sol;

  cout << sol.largestRectangleArea({2,1,5,6,2,3}) << endl;
  cout << sol.largestRectangleArea({2,4}) << endl;
}