#include <vector>
#include <unordered_map>
using namespace std;


int minChange(int amount, std::vector<int> coins, unordered_map<int, int>& memo) {
  if (memo.count(amount)) return memo[amount];
  if (amount < 0) return -1;
  if (amount == 0) return 0;
  
  int min = -1;
  for (auto coin : coins) {
    int count = minChange(amount - coin, coins, memo);
    if (count != -1) {
      count++;
      if (min == -1 || count < min) {
        min = count;
      }
    }
  }
  
  memo[amount] = min;
  return min;
}


int minChange(int amount, std::vector<int> coins) {
  unordered_map<int, int> memo;
  return minChange(amount, coins, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}