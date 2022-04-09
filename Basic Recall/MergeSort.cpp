#include <vector>

class Mergesort
{
public:
  void mergeSort(std::vector<int>& nums)
  {
    std::vector<int> tmp (nums.size());
    mergeSort(nums, tmp, 0, nums.size() - 1);
  }

private:
  void mergeSort(std::vector<int>& nums, std::vector<int>& tmp, int left, int right)
  {
    if (left < right)
    {
      int mid = left + ((right - left) >> 1);

      mergeSort(nums, tmp, left, mid);
      mergeSort(nums, tmp, mid + 1, right);

      int leftptr = left, rightptr = mid + 1;
      int fullptr = left;

      while (leftptr <= mid && rightptr <= right)
      {
        if (nums[leftptr] < nums[rightptr])
          tmp[fullptr++] = nums[leftptr++];
        else
          tmp[fullptr++] = nums[rightptr++];
      }

      while (leftptr <= mid)
        tmp[fullptr++] = nums[leftptr++];
      
      while (rightptr <= right)
        tmp[fullptr++] = nums[rightptr++];

      for (int i = left; i <= right; i++)
        nums[i] = tmp[i];
    }
  }
};