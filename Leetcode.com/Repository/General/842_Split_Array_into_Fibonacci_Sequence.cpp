// https://leetcode.com/problems/split-array-into-fibonacci-sequence/

#include <vector>
#include <string>
using namespace std;

// time: O(n^n) with pruning to O(n^2) ?
// space: O(n)

class Solution {
public:
  vector<int> splitIntoFibonacci(string& num) {
    vector<int> solution;
    solve(num, solution, 0);
    return solution;
  }
  
private:
  bool solve(string& num, vector<int>& solution, int start) {
    int n = solution.size();
    if (start == num.length() and n >= 3)
      return true;
    
    for (int i = start; i < num.length(); i++) {
      string substr = num.substr(start, i - start + 1);
      long val = stol(substr);
      if (val >= INT_MAX)
        break;
      if (i == start or substr[0] != '0') {
        if (n >= 2 and (long)solution.back() + solution[n-2] != val)
          continue;
        solution.emplace_back(val);
        if (solve(num, solution, i + 1))
          return true;
        solution.pop_back();
      }
    }
    
    return false;
  }
};