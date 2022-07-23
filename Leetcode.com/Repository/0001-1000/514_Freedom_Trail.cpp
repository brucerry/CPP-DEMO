// https://leetcode.com/problems/freedom-trail/

#include <vector>
#include <string>
using namespace std;

// r = len of ring
// k = len of key
// time: O(r^2 * k)
// space: O(r * k)

class Solution {
public:
  int findRotateSteps(string& ring, string& key) {
    vector<vector<int>> memo (ring.length(), vector<int>(key.length()));
    return solve(ring, key, 0, 0, memo);
  }
  
private:
  int solve(string& ring, string& key, int r, int k, vector<vector<int>>& memo) {
    if (k == key.length())
      return 0;
    
    if (memo[r][k])
      return memo[r][k];
    
    int ringLen = ring.length();
    
    int moveLeft = 0, moveRight = 0, i, j;
    for (i = r; ring[i] != key[k]; i = (i - 1 + ringLen) % ringLen, moveLeft++);
    for (j = r; ring[j] != key[k]; j = (j + 1) % ringLen, moveRight++);
    
    if (i == j)
      memo[r][k] = 1 + min(moveLeft, moveRight) + solve(ring, key, i, k + 1, memo);
    else {
      int result1 = 1 + moveLeft + solve(ring, key, i, k + 1, memo);
      int result2 = 1 + moveRight + solve(ring, key, j, k + 1, memo);
      memo[r][k] = min(result1, result2);
    }
    
    return memo[r][k];
  }
};