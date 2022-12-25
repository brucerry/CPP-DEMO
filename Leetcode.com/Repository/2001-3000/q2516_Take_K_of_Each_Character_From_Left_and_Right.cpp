// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

#include <string>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int takeCharacters(string s, int k) {
    int n = s.size(), res = INT_MAX, r = n - 1, counts[3] {};
    while (r >= 0 and *min_element(begin(counts), end(counts)) < k) {
      counts[s[r] - 'a']++;
      r--;
    }
    if (*min_element(begin(counts), end(counts)) < k)
      return -1;
    r++;
    res = min(res, n - r);

    for (int l = 0; l < n; l++) {
      counts[s[l] - 'a']++;
      while (r < n and counts[s[r] - 'a'] > k) {
        counts[s[r] - 'a']--;
        r++;
        res = min(res, l + 1 + n - r);
      }
    }

    return res;
  }
};