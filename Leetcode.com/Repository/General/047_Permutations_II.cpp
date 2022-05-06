// https://leetcode.com/problems/permutations-ii/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n * n!)
// space: O(n)

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    unordered_map<int, int> numCount; // num, count
    for (const int& num : nums) {
      numCount[num]++;
    }
    
    vector<vector<int>> solution;
    vector<int> permute;
    solve(nums.size(), numCount, solution, permute);
    return solution;
  }
  
private:
  void solve(int size, unordered_map<int, int>& numCount, vector<vector<int>>& solution, vector<int>& permute) {
    if (permute.size() == size) {
      solution.emplace_back(permute);
      return;
    }
    
    for (auto& [ num, count ] : numCount) {
      if (count) {
        count--;
        permute.emplace_back(num);
        solve(size, numCount, solution, permute);
        permute.pop_back();
        count++;
      }
    }
  }
};