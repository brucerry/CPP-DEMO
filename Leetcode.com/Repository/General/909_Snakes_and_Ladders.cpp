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
    
    queue<int> queue;
    queue.emplace(1);
    int move = 0;
    while (queue.size()) {
      int size = queue.size();
      
      while (size--) {
        int cur = queue.front();
        queue.pop();
        
        for (int step = 1; step <= 6; step++) {
          int next = cur + step;
          auto [ r, c ] = valToCoord(n, next);

          if (board[r][c] != -1)
            next = board[r][c];

          if (next == n * n)
            return move + 1;

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
  pair<int, int> valToCoord(int n, int val) {
    int r = (val - 1) / n;
    int c = (val - 1) % n;
    if (r & 1) // odd indexed row
      c = n - 1 - c;
    return { r, c };
  }
};