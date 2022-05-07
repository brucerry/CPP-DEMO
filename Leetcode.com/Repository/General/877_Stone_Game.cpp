// https://leetcode.com/problems/stone-game/

#include <vector>
using namespace std;

// for this question
// time: O(1)
// space: O(1)

// general
// time: O(n^2)
// space: O(n^2)

// if sum(piles) is not necessarily odd
class BottomUpDP {
public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    
    int sum = 0;
    for (const int& p : piles)
      sum += p;
    
    int half = sum >> 1;
    
    vector<vector<int>> dp (n + 1, vector<int>(n + 1));
    for (int l = n - 1; l >= 0; l--){
      for (int r = 1; r <= n; r++) {
        if (l > r)
          continue;
        
        bool even = (r - l) ^ 1; // even len = alice round, else bob round
        int leftVal = even ? piles[l] : 0;
        int rightVal = even ? piles[r-1] : 0; // r is shifted 1 for dp[][], thus have to -1 for getting value in piles[]
        
        dp[l][r] = max(dp[l+1][r] + leftVal, dp[l][r-1] + rightVal);
      }
    }
    
    return dp[0][n-1] > half;
  }
};

class TopDownMemo {
public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    
    int sum = 0;
    for (const int& p : piles)
      sum += p;
    
    int half = sum >> 1;
    
    vector<vector<int>> memo (n, vector<int>(n, -1));
    return solve(piles, 0, piles.size() - 1, memo) > half;
  }
  
private:
  int solve(vector<int>& piles, int left, int right, vector<vector<int>>& memo) {
    if (left > right)
      return 0;
    
    if (memo[left][right] != -1)
      return memo[left][right];
    
    bool even = (right - left) ^ 1; // even len = alice round, else bob round
    int leftVal = even ? piles[right] : 0;
    int rightVal = even ? piles[left] : 0;
    
    return memo[left][right] = max(leftVal + solve(piles, left + 1, right, memo),
                                   rightVal + solve(piles, left, right - 1, memo));
  }
};

class ByMaths {
public:
  bool stoneGame(vector<int>& piles) {
    return true;
  }
};