// https://leetcode.com/problems/word-search/

#include <vector>
#include <string>
#include <functional>
using namespace std;

// time: O(3^(r*c))
// space: O(r*c)

class Solution {
private:
  vector<tuple<int, int>> moves {{0,1}, {1,0}, {0,-1}, {-1,0}};

  bool exist(vector<vector<char>>& board, string word, int r, int c, int idx) {
    if (idx == word.length()) return true;
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return false;

    char currentChar = board[r][c];
    if (currentChar != word[idx]) return false;

    board[r][c] = '*';

    for (auto [ dr, dc ] : moves) {
      if (exist(board, word, r + dr, c + dc, idx + 1)) return true;
    }

    board[r][c] = currentChar;

    return false;
  }

public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        if (exist(board, word, r, c, 0)) return true;
      }
    }

    return false;
  }
};