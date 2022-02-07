#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int maxIncreasingSubseq(std::vector<int> numbers, int idx, int prevNum, unordered_map<string, int> &memo) {
  if (idx == numbers.size()) return 0;
  string key = to_string(prevNum) + ',' + to_string(idx);
  if (memo.count(key)) return memo[key];
  
  if (numbers[idx] > prevNum) {
    memo[key] = max(1 + maxIncreasingSubseq(numbers, idx + 1, numbers[idx], memo), maxIncreasingSubseq(numbers, idx + 1, prevNum, memo));
  } else {
    memo[key] = maxIncreasingSubseq(numbers, idx + 1, prevNum, memo);
  }
  
  return memo[key];
}

int maxIncreasingSubseq(std::vector<int> numbers) {
  unordered_map<string, int> memo;
  return maxIncreasingSubseq(numbers, 0, -1, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}