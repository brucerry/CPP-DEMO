#include <vector>

class Binarysearch
{
public:
  int binarySearch(std::vector<int>& nums, int target)
  {
    return binarySearch(nums, 0, nums.size() - 1, target);
  }

private:
  int binarySearch(std::vector<int>& nums, int left, int right, int target)
  {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (target == nums[mid]) return mid;
    if (target < nums[mid]) return binarySearch(nums, left, mid - 1, target);
    return binarySearch(nums, mid + 1, right, target);
  }
};