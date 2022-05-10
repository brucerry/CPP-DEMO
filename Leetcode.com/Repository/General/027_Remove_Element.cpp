// https://leetcode.com/problems/remove-element/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class TwoPointers {
public:
  int removeElement(vector<int>& nums, int val) {
    int k = 0;
    
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[k] = nums[i];
        k++;
      }
    }
    
    return k;
  }
};

class ReduceNumberOfCopy {
public:
  int removeElement(vector<int>& nums, int val) {
    int i = 0, n = nums.size();
    
    while (i < n) {
      if (nums[i] == val) {
        nums[i] = nums[n - 1];
        n--;
      }
      else
        i++;
    }
    
    return n;
  }
};