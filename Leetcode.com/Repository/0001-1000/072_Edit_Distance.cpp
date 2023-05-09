// https://leetcode.com/problems/edit-distance/

#include <string>
#include <vector>
using namespace std;

// m = len of word1
// n = len of word2
// time: O(m * n)
// space: O(m * n)
class TopDownMemo {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> memo (size1, vector<int>(size2, -1));
        return solve(word1, word2, memo, 0, 0);
    }

private:
    int solve(string& word1, string& word2, vector<vector<int>>& memo, int p1, int p2) {
        if (p1 >= word1.size() and p2 >= word2.size())
            return 0;

        if (p2 >= word2.size())
            return word1.size() - p1;

        if (p1 >= word1.size())
            return word2.size() - p2;

        int& res = memo[p1][p2];
        if (res != -1)
            return res;

        if (word1[p1] == word2[p2])
            return res = solve(word1, word2, memo, p1 + 1, p2 + 1);

        int insert = 1 + solve(word1, word2, memo, p1, p2 + 1);
        int del = 1 + solve(word1, word2, memo, p1 + 1, p2);
        int replace = 1 + solve(word1, word2, memo, p1 + 1, p2 + 1);
        return res = min({ insert, del, replace });
    }
};

// m = len of word1
// n = len of word2
// time: O(m * n)
// space: O(n)
class DP_1D {
public:
  int minDistance(string& word1, string& word2) {
    int rows = word1.length();
    int cols = word2.length();
    
    vector<int> dp (cols + 1);
    for (int c = 0; c < cols; c++)
      dp[c] = dp[c+1] + 1;
    
    for (int r = rows - 1; r >= 0; r--) {
      int prev = dp.back();
      dp.back()++;
      
      for (int c = cols - 1; c >= 0; c--) {
        int tmp = dp[c];
        
        if (word1[r] == word2[c])
          dp[c] = prev;
        else
          dp[c] = 1 + min({ dp[c], dp[c+1], prev });
        
        prev = tmp;
      }
    }
    
    return dp[0];
  }
};

// m = len of word1
// n = len of word2
// time: O(m * n)
// space: O(m * n)
class DP_2D {
public:
  int minDistance(string& word1, string& word2) {
    int rows = word1.length();
    int cols = word2.length();
    
    vector<vector<int>> dp (rows + 1, vector<int>(cols + 1));
    for (int c = cols - 1; c >= 0; c--)
      dp[rows][c] = dp[rows][c+1] + 1;
    for (int r = rows - 1; r >= 0; r--)
      dp[r][cols] = dp[r+1][cols] + 1;
    
    for (int r = rows - 1; r >= 0; r--) {
      for (int c = cols - 1; c >= 0; c--) {
        if (word1[r] == word2[c])
          dp[r][c] = dp[r+1][c+1];
        else
          dp[r][c] = 1 + min({ dp[r+1][c+1], dp[r+1][c], dp[r][c+1] });
      }
    }
    
    return dp[0][0];
  }
};