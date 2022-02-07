#include <unordered_map>
using namespace std;

int tribonacci(int n, unordered_map<int, int>& memo) {
  if (memo.count(n)) return memo[n];
  if (n < 2) return 0;
  if (n == 2) return 1;
  
  memo[n] = tribonacci(n-1, memo) + tribonacci(n-2, memo) + tribonacci(n-3, memo);
  return memo[n];
}

int tribonacci(int n) {
  unordered_map<int, int> memo;
  return tribonacci(n, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}