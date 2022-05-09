// https://leetcode.com/problems/game-of-life/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  
  /**********************
    original new state
        0     0    0
        1     0    1
        0     1    2
        1     1    3
  **********************/
  
  void gameOfLife(vector<vector<int>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int liveCount = countLiveNeighbors(board, r, c);
        
        if (board[r][c] and (liveCount == 2 or liveCount == 3))
          board[r][c] = 3;
        else if (board[r][c] == 0 and liveCount == 3)
          board[r][c] = 2;
      }
    }
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (board[r][c] == 1)
          board[r][c] = 0;
        else if (board[r][c] == 2 or board[r][c] == 3)
          board[r][c] = 1;
      }
    }
  }
  
private:
  int countLiveNeighbors(vector<vector<int>>& board, int r, int c) {
    int liveCount = 0;
    for (int i = r - 1; i <= r + 1; i++) {
      for (int j = c - 1; j <= c + 1; j++) {
        if (0 <= i and i < board.size() and 0 <= j and j < board[0].size()
            and !(i == r and j == c) and (board[i][j] == 1 or board[i][j] == 3))
          liveCount++;
      }
    }
    return liveCount;
  }
};