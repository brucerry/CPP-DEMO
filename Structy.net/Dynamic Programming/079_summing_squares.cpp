#include <unordered_map>
using namespace std;

int summingSquares(int n, unordered_map<int, int> &memo) {
  if (memo.count(n)) return memo[n];
  if (n == 0) return 0;
  
  int minSum = n;
  for (int i = 1; i * i <= n; i++) {
    int sum = 1 + summingSquares(n - i * i, memo);
    minSum = min(minSum, sum);
  }
  
  memo[n] = minSum;
  return minSum;
}

int summingSquares(int n) {
  unordered_map<int, int> memo;
  return summingSquares(n, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}