// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/

#include <vector>
#include <string>
using namespace std;

// time: O(r * c * k * (r + c))
// space: O(r * c * k)

class Solution {
public:
  int ways(vector<string>& pizza, int k) {
    int rows = pizza.size();
    int cols = pizza[0].length();
    
    int prefixSum[51][51] {};
    for (int r = 1; r <= rows; r++) {
      for (int c = 1; c <= cols; c++) {
        prefixSum[r][c] = prefixSum[r-1][c] + prefixSum[r][c-1] - prefixSum[r-1][c-1] + (pizza[r-1][c-1] == 'A');
      }
    }
    
    int memo[10][50][50];
    memset(memo, -1, sizeof(memo));
    return solve(prefixSum, 0, 0, rows, cols, k - 1, memo);
  }
  
private:
  int solve(int (*prefixSum)[51], int r, int c, int rows, int cols, int cuts, int (*memo)[50][50]) {
    if (cuts == 0)
      return getApples(prefixSum, r, c, rows - 1, cols - 1) > 0;
    
    if (memo[cuts][r][c] != -1)
      return memo[cuts][r][c];
    
    int way = 0, mod = 1e9 + 7;
    for (int i = r; i < rows - 1; i++) {
      if (getApples(prefixSum, r, c, i, cols - 1))
        way = (way + solve(prefixSum, i + 1, c, rows, cols, cuts - 1, memo)) % mod;
    }
    for (int i = c; i < cols - 1; i++) {
      if (getApples(prefixSum, r, c, rows - 1, i))
        way = (way + solve(prefixSum, r, i + 1, rows, cols, cuts - 1, memo)) % mod;
    }
    
    return memo[cuts][r][c] = way;
  }
  
  int getApples(int (*prefixSum)[51], int r1, int c1, int r2, int c2) {
    return prefixSum[r2+1][c2+1] - prefixSum[r2+1][c1] - prefixSum[r1][c2+1] + prefixSum[r1][c1];
  }
};