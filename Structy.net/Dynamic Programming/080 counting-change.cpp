#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int countingChange(int amount, std::vector<int> coins, int i, unordered_map<string, int> &memo) {
  string tag = to_string(amount) + ',' + to_string(i);
  if (memo.count(tag)) return memo[tag];
  if (amount == 0) return 1;
  if (i == coins.size()) return 0;
  
  int count = 0;
  for (int qty = 0; coins[i] * qty <= amount; qty++) {
    count += countingChange(amount - coins[i] * qty, coins, i + 1, memo);
  }
  
  memo[tag] = count;
  return count;
}

int countingChange(int amount, std::vector<int> coins) {
  unordered_map<string, int> memo;
  return countingChange(amount, coins, 0, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}