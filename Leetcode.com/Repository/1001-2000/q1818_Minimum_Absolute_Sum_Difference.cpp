// https://leetcode.com/problems/minimum-absolute-sum-difference/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int minAbsoluteSumDiff(vector<int>& n1, vector<int>& n2) {
    vector<int> sorted_n1 (n1);
    sort(sorted_n1.begin(), sorted_n1.end());

    long sum = 0, minus = 0;
    for (int i = 0; i < n1.size(); i++) {
      long absDiff = abs(n1[i] - n2[i]);
      sum += absDiff;
      auto it = lower_bound(sorted_n1.begin(), sorted_n1.end(), n2[i]);
      if (it != sorted_n1.end())
        minus = max(minus, absDiff - abs(*it - n2[i]));
      if (it != sorted_n1.begin())
        minus = max(minus, absDiff - abs(*prev(it) - n2[i]));
    }

    return (sum - minus) % 1000000007;
  }
};