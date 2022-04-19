// https://leetcode.com/problems/word-search/

#include <vector>
#include <string>
using namespace std;

// time: O(3^(r * c))
// space: O(w)

class Solution {
private:
  bool explore(vector<vector<char>>& board, string& word, int r, int c, int i) {
    if (i == word.size())
      return true;
    
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[i])
      return false;
    
    char ch = board[r][c];
    board[r][c] = '*';
    
    if (explore(board, word, r+1, c, i+1) ||
        explore(board, word, r-1, c, i+1) ||
        explore(board, word, r, c+1, i+1) ||
        explore(board, word, r, c-1, i+1))
      return true;
    
    board[r][c] = ch;
    
    return false;
  }
  
public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        if (explore(board, word, r, c, 0)) return true;
      }
    }
    return false;
  }
};