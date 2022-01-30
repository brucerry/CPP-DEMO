/*
  https://leetcode.com/problems/n-queens/
*/

#include <unordered_set>
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

  // helper functions
  vector<string> stateToString(vector<int> state, int n)
  {
    vector<string> result;
    
    for (auto i : state)
    {
      string s = string(i, '.') + "Q" + string(n - i - 1, '.');
      result.push_back(s);
    }
    
    return result;
  }
  // helper functions
  
  bool isValidState(vector<int> state, int n) {
    return n == state.size();
  }
  
  vector<int> getCandidates(vector<int> state, int n) {
    vector<int> allRange(n);
    iota(allRange.begin(), allRange.end(), 0); // 0, 1, 2, ..., n-1
    
    if (state.empty()) return allRange; // state empty means we can place a queen anywhere
    
    int rowPosition = state.size();
    
    unordered_set<int> candidates (allRange.begin(), allRange.end());
    
    for (int r = 0; r < rowPosition; r++) {
      int c = state[r];
      candidates.erase(c); // erase the colume
      int distance = rowPosition - r;
      candidates.erase(c + distance); // erase the diagonals
      candidates.erase(c - distance);
    }
    
    return vector<int> (candidates.begin(), candidates.end());
  }
  
  void search(vector<int> &state, vector<vector<string>> &solutions, int n)
  {
    if (isValidState(state, n))
    {
      vector<string> state_string = stateToString(state, n);
      solutions.push_back(state_string);
      return;
    }
    
    for (auto candidate : getCandidates(state, n))
    {
      state.push_back(candidate);
      search(state, solutions, n);
      state.pop_back(); // backtracking
    }
  }
  
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<int> state;
    search(state, solutions, n);
    return solutions;
  }
};

int main()
{
  Solution sol;
  vector<vector<string>> vvs = sol.solveNQueens(4);

  for (auto vs : vvs)
  {
    for (auto s : vs)
    {
      cout << s << endl;
    }
    cout << endl;
  }
}