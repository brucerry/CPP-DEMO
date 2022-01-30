/*
  https://leetcode.com/problems/subsets/
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

  void search(vector<int> nums, vector<int> &state, vector<vector<int>> &solutions, int begin) {
    solutions.push_back(state);
    for (int i = begin; i < nums.size(); i++) {
      state.push_back(nums[i]);
      search(nums, state, solutions, i + 1);
      state.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> solutions;
    vector<int> state;
    search(nums, state, solutions, 0);
    return solutions;
  }
};

void printSubsets(vector<vector<int>> subsets) {
  for (auto subset : subsets) {
    cout << "[ ";
    for (auto num : subset) {
      cout << num << " ";
    }
    cout << "]" << endl;
  }
}

int main() {
  vector<int> nums = {1, 3, 2};

  Solution sol;
  vector<vector<int>> subsets = sol.subsets(nums);

  printSubsets(subsets);
}