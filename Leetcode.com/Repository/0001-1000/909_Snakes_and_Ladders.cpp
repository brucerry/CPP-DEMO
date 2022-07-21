// https://leetcode.com/problems/snakes-and-ladders/

#include <vector>
#include <queue>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    
    reverse(board.begin(), board.end());
    
    vector<char> visited (n * n + 1);
    visited[1] = 1;
    
    queue<int> queue; // val
    queue.emplace(1);
    
    int move = 0;
    while (queue.size()) {
      int size = queue.size();
      
      while (size--) {
        int val = queue.front();
        queue.pop();
        
        if (val == n * n)
          return move;
        
        for (int roll = 1; roll <= 6; roll++) {
          int next = min(val + roll, n * n);
          auto [ r, c ] = valToRC(n, next);
          if (board[r][c] != -1)
            next = board[r][c];
          if (visited[next] == 0) {
            visited[next] = 1;
            queue.emplace(next);
          }
        }
      }
      move++;
    }
    
    return -1;
  }
  
private:
  pair<int, int> valToRC(int n, int val) {
    int r = (val - 1) / n;
    int c = (val - 1) % n;
    if (r & 1) // odd indexed row
      c = n - c - 1;
    return { r, c };
  }
};