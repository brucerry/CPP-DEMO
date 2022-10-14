// https://leetcode.com/problems/intersection-of-multiple-arrays/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> intersection(vector<vector<int>>& nums) {
    int counts[1001] {};
    for (const auto& num : nums) {
      for (const int& i : num) {
        counts[i]++;
      }
    }
    
    vector<int> result;
    for (int i = 1; i <= 1000; i++) {
      if (counts[i] == nums.size())
        result.emplace_back(i);
    }
    return result;
  }
};