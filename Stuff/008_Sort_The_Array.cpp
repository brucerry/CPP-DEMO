#include <iostream>
#include <vector>
using namespace std;

int findMedianOfThree(vector<int> &nums, int left, int right, int mid)
{
  if (nums[mid] < nums[left]) swap(nums[mid], nums[left]);
  if (nums[right] < nums[left]) swap(nums[right], nums[left]);
  if (nums[mid] < nums[right]) swap(nums[mid], nums[right]);
  return right;
}

int findPivotIndex(vector<int>& nums, int left, int right) {
  int medianOfThree = findMedianOfThree(nums, left, right, left + ((right - left) >> 1));
  int pivot = nums[medianOfThree];
  int smallerIndex = left - 1;

  for (int i = left; i < right; i++) {
    if (nums[i] <= pivot) {
      smallerIndex++;
      swap(nums[smallerIndex], nums[i]);
    }
  }
  swap(nums[smallerIndex + 1], nums[medianOfThree]);

  return smallerIndex + 1;
}

void mySort(vector<int>& nums, int left, int right) {
  if (left < right) {
    int pivotIndex = findPivotIndex(nums, left, right);
    mySort(nums, left, pivotIndex - 1);
    mySort(nums, pivotIndex + 1, right);
  }
}

int main() {
  int n;
  int num;

  cin >> n;

  vector<int> nums;
  nums.reserve(n);

  while (n--) {
    cin >> num;
    nums.emplace_back(num);
  }

  mySort(nums, 0, nums.size() - 1);

  cout << nums[0];
  for (int i = 1; i < nums.size(); i++) {
    cout << ' ' << nums[i];
  }
}