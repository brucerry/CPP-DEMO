// https://leetcode.com/problems/number-of-unequal-triplets-in-array/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int unequalTriplets(vector<int>& nums) {
    unordered_map<int, int> counts;
    for (const int& num : nums)
      counts[num]++;
    int res = 0, left = 0, right = nums.size();
    for (const auto& [ num, cnt ] : counts) {
      right -= cnt;
      res += left * cnt * right;
      left += cnt;
    }
    return res;
  }
};