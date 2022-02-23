/*
  time: O(n)
  space: O(n)
*/

#include <vector>
#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

int largestRectangle(vector<int>& heights) {
  int n = heights.size();
  int maxArea = 0;
  stack<pair<int, int>> stack;

  for (int i = 0; i < n; i++) {
    if (stack.size() == 0) {
      stack.push({heights[i], i});
    } else {
      auto [ topHeight, topIndex ] = stack.top();
      if (heights[i] > topHeight) {
        stack.push({heights[i], i});
      } else {
        while (heights[i] <= topHeight ) {
          topIndex = get<1>(stack.top());
          int area = topHeight  * (i - topIndex);
          //cout << area << endl;
          maxArea = max(maxArea, area);
          stack.pop();
          if (stack.size()) {
            topHeight = get<0>(stack.top());
          } else {
            break;
          }
        }
        stack.push({heights[i], topIndex});
      }
    }
  }

  while (stack.size()) {
    auto [ topHeight, topIndex ] = stack.top();
    stack.pop();
    int area = topHeight * (n - topIndex);
    maxArea = max(maxArea, area);
  }

  return maxArea;
}

int main() {
  vector<int> heights {3, 2, 4, 5, 7, 6, 1, 3, 8, 9, 11, 10, 7, 5, 2, 6};
  cout << largestRectangle(heights);
}