// https://leetcode.com/problems/magnetic-force-between-two-balls/

#include <vector>
#include <algorithm>
using namespace std;

// n = size of position
// time: O(n * log(n) + n * log(max(position)))
// space: O(log(n)) for sorting

class Solution {
public:
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int l = 1, r = position.back() - position.front();
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (canPlace(position, m, mid))
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  }

private:
  bool canPlace(vector<int>& position, int given_balls, int dist) {
    int need_balls = 1, cur = position[0];
    for (int i = 1; i < position.size(); i++) {
      if (position[i] - cur >= dist) {
        need_balls++;
        cur = position[i];
      }
    }
    return need_balls >= given_balls;
  }
};