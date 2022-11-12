// https://leetcode.com/problems/number-of-distinct-averages/

#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int distinctAverages(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    unordered_set<int> uset;
    for (int l = 0, r = nums.size() - 1; l < r; l++, r--) {
      uset.emplace(nums[l] + nums[r]);
    }
    return uset.size();
  }
};