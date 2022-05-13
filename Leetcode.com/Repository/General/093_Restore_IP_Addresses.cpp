// https://leetcode.com/problems/restore-ip-addresses/

#include <vector>
#include <string>
using namespace std;

// h = height of recursive call stack (technically at most 5)
// time: O(3^h)
// space: O(h)

class Solution {
public:
  vector<string> restoreIpAddresses(string& s) {
    if (s.length() > 12)
      return {};
    
    vector<string> solution;
    string state;
    solve(s, solution, state, 0, 0);
    return solution;
  }
  
private:
  void solve(string& s, vector<string>& solution, string& state, int dots, int start) {
    if (start == s.length() and dots == 4) {
      state.pop_back();
      solution.emplace_back(state);
      return;
    }
    
    if (dots > 4)
      return;
    
    for (int i = start; i < min(start + 3, (int)s.length()); i++) {
      string tmp = s.substr(start, i - start + 1);
      int val = stoi(tmp);
      if (val <= 255 and (i == start or tmp[0] != '0')) {
        int len = state.length();
        state += tmp + '.';
        solve(s, solution, state, dots + 1, i + 1);
        state.erase(len);
      }
    }
  }
};