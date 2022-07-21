// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maximumSum(vector<int>& arr) {
    int result = arr[0], noDelete = arr[0], oneDelete = arr[0];
    for (int i = 1; i < arr.size(); i++) {
      oneDelete = max(oneDelete + arr[i], noDelete);
      noDelete = max(noDelete + arr[i], arr[i]);
      result = max({ result, oneDelete, noDelete });
    }
    return result;
  }
};