// https://leetcode.com/problems/n-queens-ii/

#include <unordered_set>
using namespace std;

// time: O(n! * n)
// space: O(n)

class Solution {
public:
  int totalNQueens(int n) {
    unordered_set<int> usedCol, usedPosDiag, usedNegDiag;
    
    int solution = 0;
    solve(n, solution, 0, usedCol, usedPosDiag, usedNegDiag);
    return solution;
  }
  
private:
  void solve(int n, int& solution, int r, unordered_set<int>& usedCol, unordered_set<int>& usedPosDiag, unordered_set<int>& usedNegDiag) {
    if (r == n) {
      solution++;
      return;
    }
    
    for (int c = 0; c < n; c++) {
      if (usedCol.count(c) or usedPosDiag.count(r + c) or usedNegDiag.count(r - c))
        continue;
      
      usedCol.emplace(c);
      usedPosDiag.emplace(r + c);
      usedNegDiag.emplace(r - c);
      
      solve(n, solution, r + 1, usedCol, usedPosDiag, usedNegDiag);
      
      usedCol.erase(c);
      usedPosDiag.erase(r + c);
      usedNegDiag.erase(r - c);
    }
  }
};