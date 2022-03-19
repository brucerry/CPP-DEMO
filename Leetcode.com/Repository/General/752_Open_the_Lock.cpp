// https://leetcode.com/problems/open-the-lock/


#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
private:
  char rotateForward(char& ch) {
    return ((ch - '0') - 1 + 10) % 10 + '0';
  }

  char rotateBackward(char& ch) {
    return (ch - '0' + 1) % 10 + '0';
  }

public:

  int openLock(vector<string>& deadends, string& target) {
    unordered_set<string> dead (deadends.begin(), deadends.end());
    unordered_set<string> visited;
    queue<pair<int, string>> queue;
    queue.push({0, "0000"});
    visited.insert("0000");

    while (queue.size()) {
      auto [ dist, myTry ] = queue.front();
      queue.pop();

      if (myTry == target) return dist;
      if (dead.count(myTry)) continue;

      for (int i = 0; i < 4; i++) {
        string forward = myTry, backward = myTry;
        forward[i] = rotateForward(forward[i]);
        backward[i] = rotateBackward(backward[i]);
        if (visited.count(forward) == 0) {
          visited.insert(forward);
          queue.push({dist+1, forward});
        }
        if (visited.count(backward) == 0) {
          visited.insert(backward);
          queue.push({dist+1, backward});
        }
      }
    }

    return -1;
  }
};