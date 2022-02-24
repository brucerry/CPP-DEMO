// https://leetcode.com/problems/permutations-ii/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
  void solve(vector<int>& nums, unordered_map<int, int>& counter, vector<vector<int>>& result, vector<int>& candidate) {
    if (candidate.size() == nums.size()) {
      result.push_back(candidate);
      return;
    }

    for (auto& [ num, count ] : counter) {
      if (count > 0) {
        count--;
        candidate.push_back(num);
        solve(nums, counter, result, candidate);
        candidate.pop_back();
        count++;
      }
    }
  }

public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    unordered_map<int, int> counter;
    for (auto num : nums) counter[num]++;
    
    vector<vector<int>> result;
    vector<int> candidate;
    solve(nums, counter, result, candidate);
    return result;
  }
};