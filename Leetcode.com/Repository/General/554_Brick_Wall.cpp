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
    
    unordered_map<int, int> gapCount; // gap index, count
    for (const auto& row : wall) {
      int gapIndex = row[0];
      for (int i = 1; i < row.size(); i++) {
        gapCount[gapIndex]++;
        gapIndex += row[i];
      }
    }
    
    int maxCount = 0;
    for (const auto& [ _, count ] : gapCount)
      maxCount = max(maxCount, count);
    
    return rows - maxCount;
  }
};