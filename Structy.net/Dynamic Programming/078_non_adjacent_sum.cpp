#include <vector>
#include <unordered_map>
using namespace std;

int nonAdjacentSum(vector<int> nums, int i, unordered_map<int, int>& memo) {
  if (memo.count(i)) return memo[i];
  if (i >= nums.size()) return 0;
  
  int take = nums[i] + nonAdjacentSum(nums, i + 2, memo);
  int ntake = nonAdjacentSum(nums, i + 1, memo);
  
  memo[i] = max(take, ntake);
  return memo[i];
}

int nonAdjacentSum(std::vector<int> nums) {
  unordered_map<int, int> memo;
  return nonAdjacentSum(nums, 0, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}