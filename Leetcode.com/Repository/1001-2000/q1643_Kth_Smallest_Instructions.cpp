// https://leetcode.com/problems/kth-smallest-instructions/

#include <vector>
#include <string>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  string kthSmallestPath(vector<int>& destination, int k) {
    int rows = destination[0] + 1;
    int cols = destination[1] + 1;
    vector<vector<int>> dp (rows, vector<int>(cols, 1));
    for (int r = rows - 2; r >= 0; r--) {
      for (int c = cols - 2; c >= 0; c--) {
        dp[r][c] = dp[r+1][c] + dp[r][c+1];
      }
    }
    
    string result;
    int r = 0, c = 0;
    while (!(r == rows - 1 and c == cols - 1)) {
      if (c == cols - 1) {
        result.append(rows - r - 1, 'V');
        break;
      }
      else if (r == rows - 1) {
        result.append(cols - c - 1, 'H');
        break;
      }
      else if (dp[r][c+1] >= k) {
        result += 'H';
        c++;
      }
      else {
        k -= dp[r][c+1];
        result += 'V';
        r++;
      }
    }
    
    return result;
  }
};