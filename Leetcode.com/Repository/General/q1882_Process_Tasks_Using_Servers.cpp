// https://leetcode.com/problems/process-tasks-using-servers/

#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// s = len of servers
// t = len of tasks
// time: O(t * log(s))
// space: O(s)

class Solution {
public:
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    // weight, serverIndex
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> freeServers;
    for (int i = 0; i < servers.size(); i++)
      freeServers.emplace(servers[i], i);
    
    // ready time, weight, serverIndex
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> busyServers;
    
    vector<int> result (tasks.size());
    int curTime = 0;
    for (int time = 0; time < tasks.size(); time++) {
      curTime = max(curTime, time);
      if (freeServers.size() == 0)
        curTime = get<0>(busyServers.top());
      
      while (busyServers.size() and get<0>(busyServers.top()) <= curTime) {
        auto [ _, weight, serverIndex ] = busyServers.top();
        busyServers.pop();
        freeServers.emplace(weight, serverIndex);
      }
      
      auto [ weight, serverIndex ] = freeServers.top();
      freeServers.pop();
      busyServers.emplace(curTime + tasks[time], weight, serverIndex);
      result[time] = serverIndex;
    }
    
    return result;
  }
};