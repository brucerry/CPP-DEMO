// https://leetcode.com/problems/pascals-triangle/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans { { 1 } };
    
    for (int r = 1; r < numRows; r++) {
      ans.emplace_back(ans.back());
      
      for (int c = ans.back().size() - 1; c >= 1; c--) {
        ans.back()[c] += ans.back()[c - 1];
      }
      
      ans.back().emplace_back(1);
    }
    
    return ans;
  }
};