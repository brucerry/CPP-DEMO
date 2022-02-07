#include <unordered_map>
#include <string>
using namespace std;


int breakingBoundaries(int m, int n, int k, int r, int c, unordered_map<string, int> &memo) {
  if (r < 0 || r >= m || c < 0 || c >= n) return 1;
  if (k == 0) return 0;
  string key = to_string(k) + ',' + to_string(r) + ',' + to_string(c);
  if (memo.count(key)) return memo[key];
  
  int count = 0;
  count += breakingBoundaries(m, n, k - 1, r - 1, c, memo);
  count += breakingBoundaries(m, n, k - 1, r + 1, c, memo);
  count += breakingBoundaries(m, n, k - 1, r, c - 1, memo);
  count += breakingBoundaries(m, n, k - 1, r, c + 1, memo);
  
  memo[key] = count;
  return count;
}

int breakingBoundaries(int m, int n, int k, int r, int c) {
  unordered_map<string, int> memo;
  return breakingBoundaries(m, n, k, r, c, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}