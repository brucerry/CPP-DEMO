// https://leetcode.com/problems/process-tasks-using-servers/

#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// s = size of servers
// t = size of tasks
// time: O(s * log(s) + t * log(s))
// space: O(s)

class Solution {
public:
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    int n = servers.size();
    int m = tasks.size();    
    
    // weight, serverIndex
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> freeServers;
    for (int i = 0; i < n; i++) {
      freeServers.emplace(servers[i], i);
    }

    // ready time, weight, serverIndex
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> busyServers;

    int curTime = 0;
    vector<int> result (m);
    for (int time = 0; time < m; time++) {
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