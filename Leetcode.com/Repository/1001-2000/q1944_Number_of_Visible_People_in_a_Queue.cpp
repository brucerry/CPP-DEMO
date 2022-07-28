// https://leetcode.com/problems/number-of-visible-people-in-a-queue/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> result (n);
    
    vector<int> stack; // height
    for (int i = n - 1; i >= 0; i--) {
      int visible = 0;
      while (stack.size() and heights[i] > stack.back()) {
        stack.pop_back();
        visible++;
      }
      visible += stack.size() ? 1 : 0;
      result[i] = visible;
      stack.emplace_back(heights[i]);
    }
    
    return result;
  }
};