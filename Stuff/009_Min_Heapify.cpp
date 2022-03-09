#include <iostream>
#include <vector>
using namespace std;

void minHeapify(vector<int>& nums, int i) {
  int smallestIndex = i;
  int leftChildIndex = (i << 1) + 1;
  int rightChildIndex = (i << 1) + 2;

  if (leftChildIndex < nums.size() && nums[leftChildIndex] < nums[smallestIndex]) {
    smallestIndex = leftChildIndex;
  }

  if (rightChildIndex < nums.size() && nums[rightChildIndex] < nums[smallestIndex]) {
    smallestIndex = rightChildIndex;
  }

  if (smallestIndex != i) {
    swap(nums[smallestIndex], nums[i]);
    minHeapify(nums, smallestIndex);
  }
}

int main() {
  int n, num;

  cin >> n;
  vector<int> nums;
  nums.reserve(n);

  while (n--) {
    cin >> num;
    nums.emplace_back(num);
  }

  for (int i = (nums.size() >> 1) - 1; i >= 0; i--) {
    minHeapify(nums, i);
  }

  cout << nums[0];
  for (int i = 1; i < nums.size(); i++) {
    cout << ' ' << nums[i];
  }
}