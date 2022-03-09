#include <iostream>
#include <vector>
using namespace std;

int mergeSort(vector<int>& nums, vector<int>& tmp, int left, int right) {
  int count = 0;

  if (left < right) {
    int mid = left + ((right - left) >> 1);
    count += mergeSort(nums, tmp, left, mid);
    count += mergeSort(nums, tmp, mid + 1, right);
    
    int leftPtr = left;
    int rightPtr = mid + 1;
    int fullPtr = left;

    // supposed that both left & right subarray were sorted in ascending order separately

    // tmp is a buffer for storing the merged array in ascending order

    while (leftPtr <= mid && rightPtr <= right) {
      if (nums[leftPtr] <= nums[rightPtr]) {
        tmp[fullPtr++] = nums[leftPtr++];
      }
      else {
        tmp[fullPtr++] = nums[rightPtr++];
        count = (count + mid - leftPtr + 1) % 524287;
      }
    }

    while (leftPtr <= mid) {
      tmp[fullPtr++] = nums[leftPtr++];
    }

    while (rightPtr <= right) {
      tmp[fullPtr++] = nums[rightPtr++];
    }

    for (int i = left; i <= right; i++) {
      nums[i] = tmp[i];
    }
  }

  return count % 524287;
}

int inversionNumber(vector<int>& nums) {
  vector<int> tmp (nums.size());
  return mergeSort(nums, tmp, 0, nums.size() - 1);
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