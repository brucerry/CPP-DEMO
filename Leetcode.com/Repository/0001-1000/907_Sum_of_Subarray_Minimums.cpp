// https://leetcode.com/problems/sum-of-subarray-minimums/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int sumSubarrayMins(vector<int>& arr) {
    arr.emplace(arr.begin(), 0);
    arr.emplace(arr.end(), 0);
    
    int n = arr.size(), mod = 1e9 + 7;
    vector<int> stack; // index
    
    int result = 0;
    for (int i = 0; i < n; i++) {
      while (stack.size() and arr[stack.back()] > arr[i]) {
        int topi = stack.back();
        stack.pop_back();
        result = (result + (long)(topi - stack.back()) * arr[topi] * (i - topi)) % mod;
      }
      stack.emplace_back(i);
    }
    
    return result;
  }
};