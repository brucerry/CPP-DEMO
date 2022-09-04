// https://leetcode.com/problems/meeting-rooms-iii/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// m = size of meetings
// time: O(n * log(n) + m * log(n))
// space: O(n)

class Solution {
public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    
    vector<int> rooms (n);
    
    priority_queue<int, vector<int>, greater<>> freeRooms; // room id
    for (int id = 0; id < n; id++) {
      freeRooms.emplace(id);
    }
    
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> busyRooms; // availableTime, room id
    
    for (const auto& meeting : meetings) {
      int start = meeting[0], end = meeting[1];
      while (busyRooms.size() and busyRooms.top().first <= start) {
        freeRooms.emplace(busyRooms.top().second);
        busyRooms.pop();
      }
      
      if (freeRooms.size()) {
        int id = freeRooms.top();
        freeRooms.pop();
        rooms[id]++;
        busyRooms.emplace(end, id);
      }
      else {
        auto [ availableTime, id ] = busyRooms.top();
        busyRooms.pop();
        rooms[id]++;
        busyRooms.emplace(availableTime + (end - start), id);
      }
    }
    
    int result = 0;
    for (int id = 0; id < n; id++) {
      if (rooms[id] > rooms[result]) {
        result = id;
      }
    }
    
    return result;
  }
};