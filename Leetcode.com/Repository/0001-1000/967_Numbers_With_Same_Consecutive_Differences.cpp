// https://leetcode.com/problems/numbers-with-same-consecutive-differences/

#include <vector>
using namespace std;

// time: O(2^n)
// space: O(n)

class DFS_Method1 {
public:
  vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> solution { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, tmp;
    solve(n - 1, k, solution, tmp);
    return solution;
  }
  
private:
  void solve(int n, int k, vector<int>& solution, vector<int>& tmp) {
    if (n == 0)
      return;
    
    for (const int& num : solution) {
      int d = num % 10;
      if (d + k < 10)
        tmp.emplace_back(num * 10 + d + k);
      if (k and 0 <= d - k)
        tmp.emplace_back(num * 10 + d - k);
    }
    
    solution = tmp;
    tmp = {};
    solve(n - 1, k, solution, tmp);
  }
};

class DFS_Method2 {
public:
  vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> solution;
    for (int d = 1; d <= 9; d++) {
      solve(n - 1, k, solution, d);
    }
    return solution;
  }
  
private:
  void solve(int n, int k, vector<int>& solution, int num) {
    if (n == 0) {
      solution.emplace_back(num);
      return;
    }
    
    for (int d = 0; d <= 9; d++) {
      if (abs(num % 10 - d) == k) {
        solve(n - 1, k, solution, num * 10 + d);
      }
    }
  }
};