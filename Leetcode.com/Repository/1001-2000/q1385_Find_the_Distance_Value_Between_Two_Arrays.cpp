// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

#include <vector>
#include <algorithm>
using namespace std;

// n = size of arr1
// m = size of arr2
// time: O(m * log(m) + n * log(m))
// space: O(log(m)) for sorting

class Solution {
public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    sort(arr2.begin(), arr2.end());
    int result = 0;
    for (const int& num : arr1) {
      auto low = lower_bound(arr2.begin(), arr2.end(), num - d);
      auto up = upper_bound(arr2.begin(), arr2.end(), num + d);
      result += low == up;
    }
    return result;
  }
};