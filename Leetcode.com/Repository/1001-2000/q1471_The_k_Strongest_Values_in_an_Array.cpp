// https://leetcode.com/problems/the-k-strongest-values-in-an-array/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> getStrongest(vector<int>& arr, int k) {
    int n = arr.size();
    nth_element(arr.begin(), arr.begin() + (n - 1) / 2, arr.end());
    int median = arr[(n - 1) / 2];
    
    nth_element(arr.begin(), arr.begin() + k, arr.end(), [&](const int& a, const int& b) -> bool {
      int abs_a = abs(a - median);
      int abs_b = abs(b - median);
      return abs_a == abs_b ? a > b : abs_a > abs_b;
    });
    
    return vector<int>(arr.begin(), arr.begin() + k);
  }
};