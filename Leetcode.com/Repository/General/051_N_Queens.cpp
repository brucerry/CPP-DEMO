// https://leetcode.com/problems/n-queens/

#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    unordered_set<int> usedCol, usedNegDiag, usedPosDiag;
    
    vector<vector<string>> ans;
    vector<int> candidate;
    solve(n, ans, candidate, usedCol, usedNegDiag, usedPosDiag, 0);
    return ans;
  }
  
private:
  void addToAns(vector<vector<string>>& ans, vector<int>& candidate, int n) {
    vector<string> buffer (n);
    for (int r = 0; r < n; r++) {
      buffer[r] = string(candidate[r], '.') + 'Q' + string(n - candidate[r] - 1, '.');
    }
    ans.emplace_back(buffer);
  }
  
  void solve(int n, vector<vector<string>>& ans, vector<int>& candidate, unordered_set<int>& usedCol, unordered_set<int>& usedNegDiag, unordered_set<int>& usedPosDiag, int r) {
    if (r == n) {
      addToAns(ans, candidate, n);
      return;
    }
    
    for (int c = 0; c < n; c++) {
      if (usedCol.count(c) or usedNegDiag.count(r - c) or usedPosDiag.count(r + c))
        continue;
      
      usedCol.emplace(c);
      usedNegDiag.emplace(r - c);
      usedPosDiag.emplace(r + c);
    
      candidate.emplace_back(c);
      solve(n, ans, candidate, usedCol, usedNegDiag, usedPosDiag, r + 1);
      candidate.pop_back();
      
      usedCol.erase(c);
      usedNegDiag.erase(r - c);
      usedPosDiag.erase(r + c);
    }
  }
};