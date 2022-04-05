#include <vector>

class Quicksort
{
public:
  void quickSort(std::vector<int>& nums)
  {
    quickSort(nums, 0, nums.size() - 1);
  }

private:
  int findMedianOfThree(std::vector<int>& nums, int left, int right, int mid)
  {
    if (nums[mid] < nums[left]) std::swap(nums[mid], nums[left]);
    if (nums[right] < nums[left]) std::swap(nums[right], nums[left]);
    if (nums[mid] < nums[right]) std::swap(nums[mid], nums[right]);
    return right;
  }

  void quickSort(std::vector<int>& nums, int left, int right)
  {
    if (left < right)
    {
      int medianOfThree = findMedianOfThree(nums, left, right, (left + right) / 2);
      int pivot = nums[medianOfThree];
      int p = left;

      for (int i = left; i < right; i++)
      {
        if (nums[i] <= pivot)
        {
          std::swap(nums[p], nums[i]);
          p++;
        }
      }
      std::swap(nums[medianOfThree], nums[p]);

      quickSort(nums, left, p - 1);
      quickSort(nums, p + 1, right);
    }
  }
};