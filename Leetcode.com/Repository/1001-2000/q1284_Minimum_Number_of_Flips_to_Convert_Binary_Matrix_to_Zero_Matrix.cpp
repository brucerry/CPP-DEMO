// https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/

#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// time: O(r * c * 2^(r * c))
// space: O(2^(r * c))

class Solution {
public:
  int minFlips(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    
    int start = 0;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        start |= mat[r][c] << (r * cols + c);
      }
    }
    
    queue<int> queue; // state
    queue.emplace(start);
    
    unordered_set<int> visited;
    visited.insert(start);
    
    char moves[] { 0, 0, 1, 0, -1, 0 };
    
    for (int flips = 0; queue.size(); flips++) {
      for (int size = queue.size(); size; size--) {
        int state = queue.front();
        queue.pop();
        
        if (state == 0)
          return flips;
        
        for (int r = 0; r < rows; r++) {
          for (int c = 0; c < cols; c++) {
            int newState = state;
            for (int i = 0; i < 5; i++) {
              int dr = moves[i], dc = moves[i+1];
              int newr = r + dr, newc = c + dc;
              if (0 <= newr and newr < rows and 0 <= newc and newc < cols)
                newState ^= 1 << (newr * cols + newc);
            }
            if (visited.count(newState) == 0) {
              visited.insert(newState);
              queue.emplace(newState);
            }
          }
        }
      }
    }
    
    return -1;
  }
};