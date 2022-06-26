// https://leetcode.com/problems/divide-chocolate/

#include <vector>
using namespace std;

// n = size of sweetness
// s = sum of sweetness
// time: O(n * log(s))
// space: O(1)

class Solution {
public:
  int maximizeSweetness(vector<int>& sweetness, int k) {
    int l = INT_MAX, r = 0;
    for (const int& swt : sweetness) {
      l = min(l, swt);
      r += swt;
    }

    while (l < r) {
      int m = l + ((r - l + 1) >> 1);
      if (canSplit(sweetness, k + 1, m))
        l = m;
      else
        r = m - 1;
    }
    return l;
  }

private:
  bool canSplit(vector<int>& sweetness, int group, int splitMin) {
    int subarray = 0, curSum = 0;
    for (const int& swt : sweetness) {
      curSum += swt;
      if (curSum >= splitMin) {
        curSum = 0;
        subarray++;
      }
    }
    return subarray >= group;
  }
};