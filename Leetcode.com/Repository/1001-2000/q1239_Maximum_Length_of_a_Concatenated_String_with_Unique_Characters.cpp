// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

#include <vector>
#include <string>
using namespace std;

// time: O(2^n)
// space: O(n)

class Solution {
public:
  int maxLength(vector<string>& arr) {
    return solve(arr, 0, 0);
  }

private:
  int solve(vector<string>& arr, int mask, int i) {
    if (i == arr.size())
      return __builtin_popcount(mask);

    int skip = solve(arr, mask, i + 1);
    int use = 0;

    if (isUnique(arr[i], mask)) {
      for (const char& c : arr[i])
        mask |= 1 << (c - 'a');
      use = solve(arr, mask, i + 1);
    }

    return max(skip, use);
  }

  bool isUnique(const string& s, int mask) {
    for (const char& c : s) {
      if ((mask & (1 << (c - 'a'))))
        return false;
      mask |= 1 << (c - 'a');
    }
    return true;
  }
};