/*
  https://leetcode.com/problems/subsets-ii/
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

  // iterative
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> solutions, sub;
    solutions.push_back({});
    for (int i = 0; i < nums.size(); i++) {
      if (i == 0 || nums[i - 1] != nums[i]) sub = solutions;
      for (auto& j : sub) j.push_back(nums[i]);
      solutions.insert(solutions.end(), sub.begin(), sub.end());
    }
    return solutions;
  }

  // void search(vector<int> nums, vector<int> &state, vector<vector<int>> &solutions, int begin) {
  //   solutions.push_back(state);
  //   for (int i = begin; i < nums.size(); i++) {
  //     if (i == begin || nums[i - 1] != nums[i]) {
  //       state.push_back(nums[i]);
  //       search(nums, state, solutions, i + 1);
  //       state.pop_back();
  //     }
  //   }
  // }

  // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  //   sort(nums.begin(), nums.end());
  //   vector<vector<int>> solutions;
  //   vector<int> state;
  //   search(nums, state, solutions, 0);
  //   return solutions;
  // }
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
  vector<int> nums = {1, 3, 2, 2};

  Solution sol;
  vector<vector<int>> subsets = sol.subsetsWithDup(nums);

  printSubsets(subsets);
}