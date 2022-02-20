// https://leetcode.com/problems/car-fleet/

#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> distanceAndSpeed;

    int n = position.size();

    for (int i = 0; i < n; i++) {
      distanceAndSpeed.push_back({target - position[i], speed[i]});
    }

    sort(distanceAndSpeed.begin(), distanceAndSpeed.end());
    
    // vector<double> hoursToDestination;
    // for (auto [ dist, speed ] : distanceAndSpeed) {
    //   hoursToDestination.push_back((double)dist / speed);
    // }

    stack<pair<int, int>> stack;
    stack.push(distanceAndSpeed[0]);

    for (int i = 1; i < n; i++) {
      auto [ distFront, speedFront ] = stack.top();
      auto [ dist, speed ] = distanceAndSpeed[i];

      float hrsNeedFront = (float)distFront / speedFront;
      float hrsNeed = (float)dist / speed;

      if (hrsNeedFront < hrsNeed) {
        stack.push(distanceAndSpeed[i]);
      }
    }

    return stack.size();

    // int fleets = 1;
    
    // for (int i = 1; i < n; i++) {
    //   auto [ distFront, speedFront ] = distanceAndSpeed[i-1];
    //   auto [ dist, speed ] = distanceAndSpeed[i];
      
    //   if (hoursToDestination[i-1] > hoursToDestination[i]) {
    //     hoursToDestination[i] = hoursToDestination[i-1];
    //     distanceAndSpeed[i] = distanceAndSpeed[i-1];
    //   } else if (hoursToDestination[i-1] < hoursToDestination[i]) {
    //     fleets++;
    //   } else {
    //     if (speedFront < speed) {
    //       hoursToDestination[i] = hoursToDestination[i-1];
    //       distanceAndSpeed[i] = distanceAndSpeed[i-1];
    //     } else {
    //       fleets++;
    //     }
    //   }
    // }

    // return fleets;
  }
};