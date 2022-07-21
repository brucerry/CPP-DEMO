// https://leetcode.com/problems/permutations-ii/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n * n!)
// space: O(n)

class Solution {
public:
  vector<vector<int>> stateUnique(vector<int>& nums) {
    unordered_map<int, int> numCount; // num, count
    for (const int& num : nums) {
      numCount[num]++;
    }
    
    vector<vector<int>> solution;
    vector<int> state;
    solve(nums.size(), numCount, solution, state);
    return solution;
  }
  
private:
  void solve(int size, unordered_map<int, int>& numCount, vector<vector<int>>& solution, vector<int>& state) {
    if (state.size() == size) {
      solution.emplace_back(state);
      return;
    }
    
    for (auto& [ num, count ] : numCount) {
      if (count) {
        count--;
        state.emplace_back(num);
        solve(size, numCount, solution, state);
        state.pop_back();
        count++;
      }
    }
  }
};