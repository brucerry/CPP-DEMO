// https://leetcode.com/problems/find-array-given-subset-sums/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * 2^n)
// space: O(2^n)

class Solution {
public:
  vector<int> recoverArray(int n, vector<int>& sums) {
    sort(sums.begin(), sums.end());
    vector<int> result, l, r;
    
    while (sums.size() > 1) {
      l = r = {};
      int num = sums[1] - sums[0], l_zero = false;
      for (int i = 0, j = 0; i < sums.size(); i++) {
        if (sums[i] != INT_MIN) {
          l_zero |= sums[i] == 0;
          l.emplace_back(sums[i]);
          r.emplace_back(sums[i] + num);
          for (j = max(j+1, i+1); sums[j] != sums[i] + num; j++);
          sums[j] = INT_MIN;
        }
      }
      sums = l_zero ? l : r;
      result.emplace_back(num * (l_zero ? 1 : -1));
    }
    
    return result;
  }
};