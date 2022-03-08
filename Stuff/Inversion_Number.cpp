#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int inversionNumber(const vector<int>& nums) {
  if (nums.size() == 1) return 0;

  int mid = nums.size() / 2;
  vector<int> left (nums.begin(), nums.begin() + mid);
  vector<int> right (nums.begin() + mid, nums.end());

  int count = inversionNumber(left) + inversionNumber(right);

  sort(left.begin(), left.end(), greater<>());
  sort(right.begin(), right.end(), greater<>());

  int leftptr = 0, rightptr = 0;
  while (leftptr < left.size() && rightptr < right.size()) {
    if (left[leftptr] > right[rightptr]) {
      count = (count + right.size() - rightptr) % 524287;
      leftptr++;
    }
    else {
      rightptr++;
    }
  }

  return count;
}

int main() {
  vector<int> nums;
  int n;

  cin >> n;

  nums.reserve(n);

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums.emplace_back(num);
  }
  
  cout << inversionNumber(nums);
}