// https://leetcode.com/problems/k-divisible-elements-subarrays/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n^3)
// space: O(n^2)

class Solution {
public:
  int countDistinct(vector<int>& nums, int k, int p) {
    unordered_set<vector<int>, Hash> result;
    vector<int> tmp;
    for (int n = nums.size(), i = 0; i < n; i++) {
      tmp = {};
      for (int j = i, k_count = 0; j < n; j++) {
        tmp.emplace_back(nums[j]);
        if (nums[j] % p == 0)
          k_count++;
        if (k_count > k)
          break;
        result.emplace(tmp);
      }
    }
    return result.size();
  }
  
private:
  struct Hash {
    int operator()(const vector<int>& vtr) const {
      int result = 0;
      for (const int& v : vtr) {
        result ^= hash<int>()(v);
      }
      return result;
    }
  };
};