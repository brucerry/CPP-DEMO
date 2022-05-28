// https://leetcode.com/problems/pascals-triangle/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result { { 1 } };
    
    for (int r = 1; r < numRows; r++) {
      result.emplace_back(result.back());
      vector<int>& row = result.back();
      
      for (int i = row.size() - 1; i >= 1; i--) {
        row[i] += row[i-1];
      }
      row.emplace_back(1);
    }
    
    return result;
  }
};