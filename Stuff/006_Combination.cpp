#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> combination(vector<int>& nums, int size) {
  if (size == 0) return {{}};
  if (size > nums.size()) return {};

  vector<int> remainNums (nums.begin() + 1, nums.end());

  vector<vector<int>> result;

  for (auto& comb : combination(remainNums, size - 1)) {
    comb.insert(comb.begin(), nums[0]);
    result.emplace_back(comb);
  }

  for (auto& comb : combination(remainNums, size)) {
    result.emplace_back(comb);
  }

  return result;
}

int main() {
  int k;
  vector<int> nums;

  cin >> k;
  nums.reserve(k);

  while (k--) {
    int num;
    cin >> num;
    nums.emplace_back(num);
  }

  for (auto& comb : combination(nums, 6)) {
    for (int i = 0; i < comb.size(); i++) {
      cout << comb[i];
      cout << (i + 1 == comb.size() ? '\n' : ' ');
    }
  }
}