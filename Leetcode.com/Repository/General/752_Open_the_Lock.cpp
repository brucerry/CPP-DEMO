// https://leetcode.com/problems/open-the-lock/

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
  int openLock(vector<string>& deadends, string& target) {
    unordered_set<string> deadSet (deadends.begin(), deadends.end());
    unordered_set<string> visited { "0000" };
    
    if (deadSet.count("0000"))
      return -1;
    
    queue<string> queue;
    queue.emplace("0000");
    
    int turns = 0;
    
    while (queue.size()) {
      int size = queue.size();
      
      while (size--) {
        string myTry = queue.front();
        queue.pop();
        
        if (myTry == target)
          return turns;
        
        for (int i = 0; i < 4; i++) {
          increase(myTry, i);
          if (deadSet.count(myTry) == 0 and visited.count(myTry) == 0) {
            visited.emplace(myTry);
            queue.emplace(myTry);
          }
          decrease(myTry, i);
          
          decrease(myTry, i);
          if (deadSet.count(myTry) == 0 and visited.count(myTry) == 0) {
            visited.emplace(myTry);
            queue.emplace(myTry);
          }
          increase(myTry, i);
        }
      }
      
      turns++;
    }
    
    return -1;
  }
  
private:
  void increase(string& wheels, char pos) {
    wheels[pos] = wheels[pos] + 1 > '9' ? '0' : wheels[pos] + 1;
  }
  
  void decrease(string& wheels, char pos) {
    wheels[pos] = wheels[pos] - 1 < '0' ? '9' : wheels[pos] - 1;
  }
};