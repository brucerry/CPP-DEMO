// https://leetcode.com/problems/open-the-lock/

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
  int openLock(vector<string>& deadends, string& target) {
    unordered_set<string> deadendSet (deadends.begin(), deadends.end());
    if (deadendSet.count("0000"))
      return -1;
    
    queue<string> queue;
    queue.emplace("0000");
    
    unordered_set<string> visited;
    visited.emplace("0000");
    
    int turn = 0;
    while (queue.size()) {
      int size = queue.size();
      
      while (size--) {
        string code = queue.front();
        queue.pop();
        
        if (code == target)
          return turn;
        
        for (int i = 0; i < 4; i++) {
          rotate(code, i, true);
          if (visited.count(code) == 0 and deadendSet.count(code) == 0) {
            visited.emplace(code);
            queue.emplace(code);
          }
          rotate(code, i, false);
          rotate(code, i, false);
          if (visited.count(code) == 0 and deadendSet.count(code) == 0) {
            visited.emplace(code);
            queue.emplace(code);
          }
          rotate(code, i, true);
        }
      }
      turn++;
    }
    
    return -1;
  }
  
private:
  void rotate(string& code, int i, bool inc) {
    if (inc)
      code[i] = code[i] == '9' ? '0' : code[i] + 1;
    else
      code[i] = code[i] == '0' ? '9' : code[i] - 1;
  }
};