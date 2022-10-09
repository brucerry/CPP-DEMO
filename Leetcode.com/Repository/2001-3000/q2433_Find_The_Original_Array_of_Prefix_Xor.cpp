// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> findArray(vector<int>& pref) {
    for (int i = pref.size() - 1; i; i--) {
      pref[i] ^= pref[i-1];
    }
    return pref;
  }
};