// https://leetcode.com/problems/brick-wall/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int leastBricks(vector<vector<int>>& wall) {
    int rows = wall.size();
    
    unordered_map<int, int> gapCount; // gap position, count
    for (int r = 0; r < rows; r++) {
      int gap_pos = 0;
      
      for (int c = 0; c < wall[r].size() - 1; c++) {
        gap_pos += wall[r][c];
        gapCount[gap_pos]++;
      }
    }
    
    int maxCount = 0;
    for (const auto& [ _, count ] : gapCount)
      maxCount = max(maxCount, count);
    
    return rows - maxCount;
  }
};