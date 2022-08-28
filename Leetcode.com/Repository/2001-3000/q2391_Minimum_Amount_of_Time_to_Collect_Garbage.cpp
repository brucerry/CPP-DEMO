// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

#include <vector>
#include <string>
#include <numeric>
using namespace std;

// g = size of garbage
// n = max len of garbage
// t = size of travel
// time: O(t + g * n)
// space: O(1)

class Solution {
public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int dists[3] {};
    for (int i = 1; i < travel.size(); i++) {
      travel[i] += travel[i-1];
    }
    
    int mins = 0;
    for (int i = 0; i < garbage.size(); i++) {
      for (const char& c : garbage[i]) {
        int id = c == 'M' ? 0 : c == 'P' ? 1 : 2;
        dists[id] = i ? travel[i-1] : 0;
        mins++;
      }
    }
    
    return mins + accumulate(begin(dists), end(dists), 0);
  }
};