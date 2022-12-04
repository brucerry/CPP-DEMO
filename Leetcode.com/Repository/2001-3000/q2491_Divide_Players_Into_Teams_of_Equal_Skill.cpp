// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  long long dividePlayers(vector<int>& skill) {
    sort(skill.begin(), skill.end());
    long res = 0, equal_skill = skill.front() + skill.back();
    for (int l = 0, r = skill.size() - 1; l < r; l++, r--) {
      int grp_skill = skill[l] + skill[r];
      if (grp_skill != equal_skill)
        return -1;
      res += skill[l] * skill[r];
    }
    return res;
  }
};