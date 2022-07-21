// https://leetcode.com/problems/the-latest-time-to-catch-a-bus/

#include <vector>
#include <algorithm>
using namespace std;

// b = size of bus
// p = size of passengers
// time: O(b * log(b) + p * log(p))
// space: O(log(b) + log(p)) for sorting

class Solution {
public:
  int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());
    
    int p = 0, latest;
    for (const int& bus : buses) {
      int count = 0, lastPassenger;
      while (count < capacity and p < passengers.size() and passengers[p] <= bus) {
        if (p == 0 or passengers[p-1] != passengers[p] - 1)
          latest = passengers[p] - 1;
        count++;
        lastPassenger = passengers[p];
        p++;
      }
      if (count < capacity and lastPassenger != bus)
        latest = bus;
    }
    
    return latest;
  }
};