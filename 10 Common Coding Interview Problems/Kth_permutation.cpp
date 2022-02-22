/*
  time: O(n^2)
  space: O(n)
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<char> KthPermutation(int n, int k) {
  vector<char> nums;
  vector<int> facts (n + 1, 1);
  for (int i = 1; i <= n; i++) {
    nums.push_back('0' + i);
    facts[i] = facts[i-1] * i;
  }

  k--; // starting from 0
  vector<char> ans;

  while (n > 0) {
    int partLength = facts[n] / n;
    int i = k / partLength;
    ans.push_back(nums[i]);
    nums.erase(nums.begin() + i);
    n--;
    k %= partLength;
  }

  return ans;
}

int main() {
  int n = 4; // '1' to '4'
  int k = 16; // 16 = 15-th if start from 0
  for (auto num : KthPermutation(n, k)) {
    cout << num;
  }
}