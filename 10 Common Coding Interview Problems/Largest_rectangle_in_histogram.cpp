/*
  time: O(n)
  space: O(n)
*/

#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int largestRectangle(vector<int>& heights) {
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

int main() {
  vector<int> heights {3, 2, 4, 5, 7, 6, 1, 3, 8, 9, 11, 10, 7, 5, 2, 6};
  cout << largestRectangle(heights);
}