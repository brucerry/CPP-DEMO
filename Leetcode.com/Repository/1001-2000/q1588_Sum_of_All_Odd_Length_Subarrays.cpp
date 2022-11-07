// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int sum = 0, n = arr.size();
    for (int i = 0; i < n; i++) {
      sum += ((i + 1) * (n - i) + 1) / 2 * arr[i];
    }
    return sum;
  }
};