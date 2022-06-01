// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int rows = heights.size();
    int cols = heights[0].size();
    
    vector<vector<char>> visitedPacific (rows, vector<char>(cols)), visitedAtlantic = visitedPacific;
    
    for (int r = 0; r < rows; r++) {
      traverse(heights, r, 0, -1, visitedPacific);
      traverse(heights, r, cols - 1, -1, visitedAtlantic);
    }
    
    for (int c = 0; c < cols; c++) {
      traverse(heights, 0, c, -1, visitedPacific);
      traverse(heights, rows - 1, c, -1, visitedAtlantic);
    }
    
    vector<vector<int>> result;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (visitedPacific[r][c] and visitedAtlantic[r][c])
          result.push_back({ r, c });
      }
    }
    
    return result;
  }
  
private:
  void traverse(vector<vector<int>>& heights, int r, int c, int prev, vector<vector<char>>& visited) {
    if (r < 0 or r >= heights.size() or c < 0 or c >= heights[0].size() or prev > heights[r][c] or visited[r][c])
      return;
    
    visited[r][c] = 1;
    
    traverse(heights, r+1, c, heights[r][c], visited);
    traverse(heights, r-1, c, heights[r][c], visited);
    traverse(heights, r, c+1, heights[r][c], visited);
    traverse(heights, r, c-1, heights[r][c], visited);
  }
};