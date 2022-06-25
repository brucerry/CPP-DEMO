// https://leetcode.com/problems/bitwise-ors-of-subarrays/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(30 * n) => O(n) for at most 30 different bitwise OR result in range [0, 10^9 (30-bit)]
// space: O(n)

class Solution {
public:
  int subarrayBitwiseORs(vector<int>& arr) {
    vector<int> result;
    for (int i = 0, l = 0, r = 0; i < arr.size(); i++, l = r, r = result.size()) {
      result.emplace_back(arr[i]);
      for (int j = l; j < r; j++) {
        if ((arr[i] | result[j]) != result.back())
          result.emplace_back(arr[i] | result[j]);
      }
    }
    return unordered_set<int>(result.begin(), result.end()).size();
  }
};