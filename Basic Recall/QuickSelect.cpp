#include <vector>

// k = nums.size() - k if find k-th largest
// k = k - 1 if find k-th smallest

class Quickselect
{
public:
  int quickSelect(std::vector<int>& nums, int k)
  {
    return quickSelect(nums, 0, nums.size() - 1, k);
  }

private:
  int quickSelect(std::vector<int>& nums, int left, int right, int k)
  {
    if (left < right)
    {
      int pivot = nums[right];
      int p = left;

      for (int i = left; i < right; i++)
      {
        if (nums[i] <= pivot)
        {
          std::swap(nums[i], nums[p]);
          p++;
        }
      }
      std::swap(nums[right], nums[p]);

      if (k < p) return quickSelect(nums, left, p - 1, k);
      else if (p < k) return quickSelect(nums, p + 1, right, k);
      else return nums[p];
    }

    return -1;
  }
};