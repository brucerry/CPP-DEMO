#include <vector>
#include <unordered_map>
using namespace std;

bool arrayStepper(std::vector<int> numbers, int i, unordered_map<int, bool> &memo) {
  if (memo.count(i)) return memo[i];
  if (i == numbers.size() - 1) return true;
  if (i >= numbers.size()) return false;
  
  for (int step = 1; step <= numbers[i]; step++) {
    if (arrayStepper(numbers, i + step, memo)) {
      memo[i] = true;
      return true;
    }
  }
  
  memo[i] = false;
  return false;
}

bool arrayStepper(std::vector<int> numbers) {
  unordered_map<int, bool> memo;
  return arrayStepper(numbers, 0, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}