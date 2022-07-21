// https://leetcode.com/problems/check-if-move-is-legal/

#include <vector>
using namespace std;

// time: O(8 * 8) => O(1)
// space: O(8) => O(1)

class Solution {
public:
  bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
    vector<pair<int, int>> moves {
      { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 },
      { 1, 1 }, { -1, -1 }, { 1, -1 }, { -1, 1 }
    };
    
    for (const auto& move : moves) {
      if (isValid(board, rMove, cMove, color, move))
        return true;
    }
    return false;
  }
  
private:
  bool isValid(vector<vector<char>>& board, int rMove, int cMove, char color, const pair<int, int>& move) {
    auto [ dr, dc ] = move;
    int r = rMove + dr;
    int c = cMove + dc;
    int len = 2;
    
    while (0 <= r and r < 8 and 0 <= c and c < 8 and board[r][c] != '.') {
      if (board[r][c] == color)
        return len >= 3;
      r += dr;
      c += dc;
      len++;
    }
    return false;
  }
};