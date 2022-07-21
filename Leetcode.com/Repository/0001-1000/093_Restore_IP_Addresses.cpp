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
    int n = s.length();
    
    if (n < 4 or n > 12)
      return {};
    
    vector<string> solution;
    string address;
    solve(s, solution, address, 0, 0);
    return solution;
  }
  
private:
  void solve(string& s, vector<string>& solution, string& address, int dot, int start) {
    if (start == s.length() and dot == 4) {
      address.pop_back();
      solution.emplace_back(address);
      return;
    }
    
    if (dot > 4)
      return;
    
    for (int i = start; i < min(start + 3, (int)s.length()); i++) {
      string field = s.substr(start, i - start + 1);
      int val = stoi(field);
      if (val <= 255 and (i == start or field[0] != '0')) {
        int len = address.length();
        address += field + '.';
        solve(s, solution, address, dot + 1, i + 1);
        address.erase(len);
      }
    }
  }
};