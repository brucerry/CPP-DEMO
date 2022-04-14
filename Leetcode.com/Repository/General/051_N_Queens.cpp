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

    vector<vector<string>> ans;
    vector<int> state; // i = row, state[i] = col
    solve(n, ans, state, usedCol, usedPosDiag, usedNegDiag, 0);
    return ans;
  }
  
private:
  void push_state_to_ans(vector<vector<string>>& ans, vector<int>& state) {
    vector<string> buffer;
    for (const int& col : state) {
      string s = string(col, '.') + 'Q' + string(state.size() - col - 1, '.');
      buffer.emplace_back(s);
    }
    ans.emplace_back(buffer);
  }
  
  void solve(int n, vector<vector<string>>& ans, vector<int>& state, unordered_set<int>& usedCol, unordered_set<int>& usedPosDiag, unordered_set<int>& usedNegDiag, int r) {
    if (r == n) {
      push_state_to_ans(ans, state);
      return;
    }
    
    for (int c = 0; c < n; c++) {
      if (usedCol.count(c) || usedPosDiag.count(r + c) || usedNegDiag.count(r - c))
        continue;

      usedCol.emplace(c);
      usedPosDiag.emplace(r + c);
      usedNegDiag.emplace(r - c);

      state.emplace_back(c);
      solve(n, ans, state, usedCol, usedPosDiag, usedNegDiag, r + 1);
      state.pop_back();

      usedCol.erase(c);
      usedPosDiag.erase(r + c);
      usedNegDiag.erase(r - c);
    }
  }
};