// https://leetcode.com/problems/determine-if-two-strings-are-close/

#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool closeStrings(string word1, string word2) {
    int cnt1[26] {}, cnt2[26] {};
    int mask1 = 0, mask2 = 0;
    for (const char& c : word1) {
      cnt1[c - 'a']++;
      mask1 |= 1 << (c - 'a');
    }
    for (const char& c : word2) {
      cnt2[c - 'a']++;
      mask2 |= 1 << (c - 'a');
    }
    sort(begin(cnt1), end(cnt1));
    sort(begin(cnt2), end(cnt2));
    return memcmp(cnt1, cnt2, 26 * sizeof(int)) == 0 and mask1 == mask2;
  }
};