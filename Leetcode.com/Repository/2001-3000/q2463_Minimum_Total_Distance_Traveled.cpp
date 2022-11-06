// https://leetcode.com/problems/minimum-total-distance-traveled/

#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// r = size of robot
// f = size of factory
// k = factory[i][1] = limit
// time: O(r * f * k)
// space: O(r * f)

class Solution {
public:
  long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());
    long memo[100][100];
    memset(memo, -1, sizeof(memo));
    return solve(robot, factory, memo, robot.size(), factory.size(), 0, 0);
  }

private:
  long solve(vector<int>& robot, vector<vector<int>>& factory, long (*memo)[100], int robot_len, int factory_len, int i, int j) {
    if (i == robot_len)
      return 0;

    if (j == factory_len)
      return LONG_MAX;

    long& result = memo[i][j];
    if (result != -1)
      return result;

    // skip current factory
    result = solve(robot, factory, memo, robot_len, factory_len, i, j + 1);

    // fix at most factory[j][1] robots
    long curcost = 0;
    for (int k = i; k < robot_len and k - i < factory[j][1]; k++) {
      curcost += abs(robot[k] - factory[j][0]);
      long fix = solve(robot, factory, memo, robot_len, factory_len, k + 1, j + 1);
      if (fix != LONG_MAX)
        result = min(result, fix + curcost);
    }

    return result;
  }
};