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
      for (int c = 1; c < wall[r].size(); c++) {
        gap_pos += wall[r][c-1];
        gapCount[gap_pos]++;
      }
    }
    
    int count = 0;
    for (const auto& [ _, c ] : gapCount)
      count = max(count, c);
    
    return rows - count;
  }
};