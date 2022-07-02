// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

#include <vector>
using namespace std;

// time: O(n * log(max(dist) * 100))
// space: O(1)

class Solution {
public:
  int minSpeedOnTime(vector<int>& dist, double hour) {
    int l = 1, r = 0;
    for (int i = 0; i < dist.size(); i++) {
      if (i >= hour)
        return -1;
      r = max(r, dist[i] * 100);
    }
    
    while (l < r) {
      int m = l + ((r - l) >> 1);
      if (isOnTime(dist, hour, m))
        r = m;
      else
        l = m + 1;
    }
    return r;
  }
  
private:
  bool isOnTime(vector<int>& dist, double hour, int speed) {
    double need = 0;
    int n = dist.size();
    for (int i = 0; i < n; i++) {
      double h = (double)dist[i] / speed;
      need += i == n - 1 ? h : ceil(h);
    }
    return need <= hour;
  }
};