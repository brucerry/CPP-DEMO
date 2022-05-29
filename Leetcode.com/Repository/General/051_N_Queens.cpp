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
    unordered_set<int> usedCol, usedPosDiag, usedNegDiag;
    
    vector<vector<string>> solution;
    vector<int> state;
    solve(n, solution, state, usedCol, usedPosDiag, usedNegDiag, 0);
    return solution;
  }
  
private:
  void solve(int n, vector<vector<string>>& solution, vector<int>& state, unordered_set<int>& usedCol, unordered_set<int>& usedPosDiag, unordered_set<int>& usedNegDiag, int r) {
    if (r == n) {
      addSolution(n, solution, state);
      return;
    }
    
    for (int c = 0; c < n; c++) {
      if (usedCol.count(c) or usedPosDiag.count(r + c) or usedNegDiag.count(r - c))
        continue;
      
      usedCol.emplace(c);
      usedPosDiag.emplace(r + c);
      usedNegDiag.emplace(r - c);
      
      state.emplace_back(c);
      solve(n, solution, state, usedCol, usedPosDiag, usedNegDiag, r + 1);
      state.pop_back();
      
      usedCol.erase(c);
      usedPosDiag.erase(r + c);
      usedNegDiag.erase(r - c);
    }
  }
  
  void addSolution(int n, vector<vector<string>>& solution, vector<int>& state) {
    vector<string> buffer (n);
    for (int r = 0; r < n; r++) {
      int c = state[r];
      buffer[r] = string(c, '.') + 'Q' + string(n - c - 1, '.');
    }
    solution.emplace_back(buffer);
  }
};