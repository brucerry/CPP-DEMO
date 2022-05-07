// https://leetcode.com/problems/check-if-move-is-legal/

#include <vector>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
  bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {    
    vector<pair<int, int>> moves {
      {0, 1}, {0, -1}, {1, 0}, {-1, 0},
      {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };
    
    for (const auto& move : moves) {
      if (legal(board, rMove, cMove, color, move))
        return true;
    }
    
    return false;
  }
  
private:
  bool legal(vector<vector<char>>& board, int r, int c, char color, const pair<int, int>& move) {
    auto [ dr, dc ] = move;
    r += dr;
    c += dc;
    int len = 2;
    
    while (0 <= r and r < board.size() and 0 <= c and c < board[0].size()) {
      if (board[r][c] == '.')
        return false;
      if (board[r][c] == color)
        return len >= 3;
      
      r += dr;
      c += dc;
      len++;
    }
    
    return false;
  }
};