// https://leetcode.com/problems/minesweeper/

#include <vector>
#include <queue>
using namespace std;

// time: O(r * c * 8) => O(r * c)
// space: O(8) => O(1)

class Solution {
public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int rows = board.size();
    int cols = board[0].size();
    
    int r = click[0], c = click[1];
    if (board[r][c] != 'M' and board[r][c] != 'E')
      return board;
    
    if (board[r][c] == 'M') {
      board[r][c] = 'X';
      return board;
    }
    
    vector<pair<int, int>> neighbors {
      { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 },
      { 1, 1 }, { -1, -1 }, { 1, -1 }, { -1, 1 }
    };
    
    queue<pair<int, int>> queue; // cur_r, cur_c
    queue.emplace(r, c);
    
    while (queue.size()) {
      auto [ cur_r, cur_c ] = queue.front();
      queue.pop();
      
      int neighborMine = 0;
      for (const auto& [ dr, dc ] : neighbors) {
        int newr = cur_r + dr;
        int newc = cur_c + dc;
        if (0 <= newr and newr < rows and 0 <= newc and newc < cols and board[newr][newc] == 'M')
          neighborMine++;
      }
      
      board[cur_r][cur_c] = neighborMine ? neighborMine + '0' : 'B';
      if (board[cur_r][cur_c] == 'B') {
        for (const auto& [ dr, dc ] : neighbors) {
          int newr = cur_r + dr;
          int newc = cur_c + dc;
          if (0 <= newr and newr < rows and 0 <= newc and newc < cols and board[newr][newc] == 'E') {
            board[newr][newc] = 'B';
            queue.emplace(newr, newc);
          }
        }
      }
    }
    
    return board;
  }
};