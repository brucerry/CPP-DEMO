// https://leetcode.com/problems/equal-row-and-column-pairs/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
  int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    
    unordered_map<vector<int>, int, Hash> rowCount, colCount;
    for (const auto& row : grid)
      rowCount[row]++;
    
    vector<int> col (n);
    for (int c = 0; c < n; c++) {
      for (int r = 0; r < n; r++) {
        col[r] = grid[r][c];
      }
      colCount[col]++;
    }
    
    int pairs = 0;
    for (const auto& [ row, rCount ] : rowCount) {
      if (colCount.count(row))
        pairs += rCount * colCount[row];
    }
    
    return pairs;
  }
  
private:
  struct Hash {
    int operator()(const vector<int>& nums) const {
      int result = 0;
      for (const int& num : nums)
        result ^= num;
      return result;
    }
  };
};