// https://leetcode.com/problems/partition-array-according-to-given-pivot/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    vector<int> result (n);
    
    int less = 0, equal = 0, greater = 0;
    for (const int& num : nums) {
      if (num < pivot)
        less++;
      else if (num == pivot)
        equal++;
      else
        greater++;
    }
    
    int i = 0, j = less, k = less + equal;
    for (const int& num : nums) {
      if (num < pivot)
        result[i++] = num;
      else if (num == pivot)
        result[j++] = num;
      else
        result[k++] = num;
    }
    
    return result;
  }
};