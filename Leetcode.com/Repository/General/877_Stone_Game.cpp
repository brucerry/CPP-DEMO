// https://leetcode.com/problems/stone-game/

#include <vector>
using namespace std;

// for this question
// time: O(1)
// space: O(1)

// general
// time: O(n^2)
// space: O(n^2) 2d array, O(n) 1d array

// if sum(piles) is not necessarily odd
class BottomUpDP_2D {
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
        
        bool aliceTurn = (r - l) & 1;
        int leftVal = aliceTurn ? piles[l] : 0;
        int rightVal = aliceTurn ? piles[r-1] : 0; // r is shifted 1 for dp[], thus have to -1 for getting value in piles[]
        
        dp[l][r] = max(dp[l+1][r] + leftVal, dp[l][r-1] + rightVal);
      }
    }
    
    return dp[0][n] > half;
  }
};

class BottomUpDP_1D {
public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    
    int sum = 0;
    for (const int& p : piles)
      sum += p;
    
    int half = sum >> 1;
    
    vector<int> dp (n + 1);
    for (int l = n - 1; l >= 0; l--){
      for (int r = 1; r <= n; r++) {
        if (l > r)
          continue;
        
        bool aliceTurn = (r - l) & 1;
        int leftVal = aliceTurn ? piles[l] : 0;
        int rightVal = aliceTurn ? piles[r-1] : 0; // r is shifted 1 for dp[], thus have to -1 for getting value in piles[]
        
        dp[r] = max(dp[r] + leftVal, dp[r-1] + rightVal);
      }
    }
    
    return dp[n] > half;
  }
};

class TopDownMemo {
public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    
    int sum = 0;
    for (const int& num : piles)
      sum += num;
    
    int half = sum >> 1;
    
    vector<vector<int>> memo (n, vector<int>(n, -1));
    return solve(piles, 0, piles.size() - 1, memo) > half;
  }
  
private:
  int solve(vector<int>& piles, int l, int r, vector<vector<int>>& memo) {
    if (l > r)
      return 0;
    
    if (memo[l][r] != -1)
      return memo[l][r];
    
    bool aliceTurn = (r - l) & 1;
    int leftVal = aliceTurn ? piles[l] : 0;
    int rightVal = aliceTurn ? piles[r] : 0;
    
    return memo[l][r] = max(leftVal + solve(piles, l + 1, r, memo),
                            rightVal + solve(piles, l, r - 1, memo));
  }
};

class ByMaths {
public:
  bool stoneGame(vector<int>& piles) {
    return true;
  }
};