#include <unordered_map>
using namespace std;

int fib(int n, unordered_map<int, int>& memo) {
  if (memo.count(n)) return memo[n];
  if (n < 2) return n;
  
  memo[n] = fib(n-1, memo) + fib(n-2, memo);
  return memo[n];
}

int fib(int n) {
  unordered_map<int, int> memo;
  return fib(n, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}