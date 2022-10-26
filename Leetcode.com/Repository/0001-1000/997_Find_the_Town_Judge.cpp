// https://leetcode.com/problems/find-the-town-judge/

#include <vector>
using namespace std;

// t = size of trust
// time: O(t + n)
// space: O(1)

class Solution {
public:
  int findJudge(int n, vector<vector<int>>& trust) {
    int counts[1001] {};
    for (const auto& t : trust) {
      counts[t[0]]--;
      counts[t[1]]++;
    }
    for (int i = 1; i <= n; i++) {
      if (counts[i] == n - 1)
        return i;
    }
    return -1;
  }
};