#include <iostream>
#include <vector>
using namespace std;


/*
  time: O(log(n))
  space: O(1)
*/

int findFirst(vector<int>& nums, int target) {
  if (nums.front() == target) return 0;

  int l = 0, r = nums.size() - 1;

  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] == target) {
      if (nums[m - 1] < nums[m]) return m;
      else r = m - 1;
    }
    else if (nums[m] < target) l = m + 1;
    else r = m - 1;
  }
  return -1;
}

int findEnd(vector<int>& nums, int target) {
  if (nums.back() == target) return nums.size() - 1;

  int l = 0, r = nums.size() - 1;

  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] == target) {
      if (nums[m + 1] > nums[m]) return m;
      else l = m + 1;
    }
    else if (nums[m] < target) l = m + 1;
    else r = m - 1;
  }
  return -1;
}

pair<int, int> firstAndLast(vector<int> nums, int target) {
  return { findFirst(nums, target), findEnd(nums, target) };
}

int main() {
  auto [ i1, i2 ] = firstAndLast({2,4,5,5,5,7,9,10,11,12,12,12,12,12,12,12,12,13,13,13,14,99,100}, 12);
  cout << i1 << ' ' << i2;
}
