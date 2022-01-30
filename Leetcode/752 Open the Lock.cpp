/*
  https://leetcode.com/problems/open-the-lock/
*/

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <tuple>
using namespace std;



class Solution {
public:

  char rotateForward(char d) {
    int ans = d - '0' - 1;
    return ans < 0 ? '9' : d - 1;
  }

  char rotateBackward(char d) {
    int ans = d - '0' + 1;
    return ans > 9 ? '0' : d + 1;
  }

  int openLock(vector<string> deadends, string target) {
    unordered_set<string> dead (deadends.begin(), deadends.end());
    unordered_set<string> visited;
    queue<tuple<int, string>> queue;
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

#include <iostream>


int main() {
  Solution sol;
  cout << sol.openLock({"0201","0101","0102","1212","2002"}, "0202");
}