// https://leetcode.com/problems/reverse-pairs/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n))

class Solution {
public:
  int reversePairs(vector<int>& nums) {
    return merge(nums.begin(), nums.end());
  }

private:
  int merge(vector<int>::iterator begin, vector<int>::iterator end) {
    int result = 0;
    if (end - begin >= 2) {
      auto mid = begin + (end - begin) / 2;
      result += merge(begin, mid);
      result += merge(mid, end);

      for (auto i = begin, j = mid; i != mid; i++) {
        while (j != end and *i > 2L * *j)
          j++;
        result += j - mid;
      }

      inplace_merge(begin, mid, end);
    }
    return result;
  }
};