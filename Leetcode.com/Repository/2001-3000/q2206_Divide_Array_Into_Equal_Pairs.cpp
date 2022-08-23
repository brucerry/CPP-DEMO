// https://leetcode.com/problems/divide-array-into-equal-pairs/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool divideArray(vector<int>& nums) {
    int counts[501] {};
    for (const int& num : nums)
      counts[num]++;
    return all_of(begin(counts), end(counts), [](const int& count) -> bool {
      return count % 2 == 0;
    });
  }
};