// https://leetcode.com/problems/dungeon-game/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(c)
class BottomUpDP_1D {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int rows = dungeon.size();
    int cols = dungeon[0].size();
    
    vector<int> dp (cols);
    for (int r = rows - 1; r >= 0; r--) {
      for (int c = cols - 1; c >= 0; c--) {
        if (r == rows - 1 and c == cols - 1)
          dp[c] = dungeon[r][c] < 0 ? -dungeon[r][c] + 1 : 1;
        else {
          int rightHP = c + 1 == cols ? INT_MAX : dp[c+1];
          int downHP = r + 1 == rows ? INT_MAX : dp[c];
          int need = min(rightHP, downHP) - dungeon[r][c];
          dp[c] = need <= 0 ? 1 : need;
        }
      }
    }
    
    return dp[0];
  }
};

// time: O(r * c)
// space: O(r * c)
class BottomUpDP_2D {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int rows = dungeon.size();
    int cols = dungeon[0].size();
    
    vector<vector<int>> dp (rows, vector<int>(cols));
    for (int r = rows - 1; r >= 0; r--) {
      for (int c = cols - 1; c >= 0; c--) {
        if (r == rows - 1 and c == cols - 1)
          dp[r][c] = dungeon[r][c] < 0 ? -dungeon[r][c] + 1 : 1;
        else {
          int rightHP = c + 1 == cols ? INT_MAX : dp[r][c+1];
          int downHP = r + 1 == rows ? INT_MAX : dp[r+1][c];
          int need = min(rightHP, downHP) - dungeon[r][c];
          dp[r][c] = need <= 0 ? 1 : need;
        }
      }
    }
    
    return dp[0][0];
  }
};

// time: O(r * c)
// space: O(r * c)
class TopDownMemo {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int rows = dungeon.size();
    int cols = dungeon[0].size();
    vector<vector<int>> memo (rows, vector<int>(cols, -1));
    return solve(dungeon, 0, 0, memo);
  }
  
private:
  int solve(vector<vector<int>>& dungeon, int r, int c, vector<vector<int>>& memo) {
    int rows = dungeon.size();
    int cols = dungeon[0].size();
    
    if (r >= rows or c >= cols)
      return INT_MAX;
    
    if (r == rows - 1 and c == cols - 1)
      return dungeon[r][c] < 0 ? -dungeon[r][c] + 1 : 1;
    
    if (memo[r][c] != -1)
      return memo[r][c];
    
    int rightHP = solve(dungeon, r, c+1, memo);
    int downHP = solve(dungeon, r+1, c, memo);
    int need = min(rightHP, downHP) - dungeon[r][c];
    
    return memo[r][c] = need <= 0 ? 1 : need;
  }
};