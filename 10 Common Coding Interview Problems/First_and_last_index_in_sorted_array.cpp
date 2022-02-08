#include <iostream>
#include <vector>
#include <tuple>
using namespace std;


/*
  using Binary Search
    
  time: O(log(n))
  space: O(1)
*/
int findFirst(vector<int> nums, int target) {
  if (nums.front() == target) return 0;
  int left = 0, right = nums.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
      if (nums[mid - 1] < nums[mid]) return mid;
      else right = mid - 1;
    }
    else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
  }
  return -1;
}

int findEnd(vector<int> nums, int target) {
  if (nums.back() == target) return nums.size() - 1;
  int left = 0, right = nums.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
      if (nums[mid + 1] > nums[mid]) return mid;
      else left = mid + 1;
    }
    else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
  }
  return -1;
}

tuple<int, int> firstAndLast(vector<int> nums, int target) {
  return { findFirst(nums, target), findEnd(nums, target) };
}


// time: O(n)
// space: O(1)
// tuple<int, int> firstAndLast(vector<int> nums, int target) {
//   int i = 0, j = nums.size() - 1;

//   while ((i < nums.size() || j >= 0) && (i <= j)) {
//     if (nums[i] == target && nums[j] == target) return { i, j };
//     if (nums[i] != target) i++;
//     if (nums[j] != target) j--;
//   }

//   return { -1, -1 };
// }

int main() {
  auto [ i1, i2 ] = firstAndLast({2,4,5,5,5,7,9,10,11,12,12,12,12,12,12,12,12,13,13,13,14,99,100}, 12);
  cout << i1 << " " << i2;
}
