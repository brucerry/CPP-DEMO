// https://leetcode.com/problems/minimum-jumps-to-reach-home/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    forbidden.emplace_back(0);
    bool visited[2][6000] {}; // 0: from backward, 1: from forward
    for (const int& f : forbidden) {
      visited[0][f] = visited[1][f] = 1;
    }

    queue<pair<int, bool>> queue; // pos, from
    queue.emplace(0, 0);

    int jumps = 0;
    while (queue.size()) {
      for (int size = queue.size(); size; size--) {
        auto [ pos, from ] = queue.front();
        queue.pop();
        if (pos == x)
          return jumps;
        int forward = pos + a, backward = pos - b;
        if (forward < 6000 and !visited[1][forward]) {
          visited[1][forward] = 1;
          queue.emplace(forward, 1);
        }
        if (from and backward >= 0 and !visited[0][backward]) {
          visited[0][backward] = 1;
          queue.emplace(backward, 0);
        }
      }
      jumps++;
    }

    return -1;
  }
};