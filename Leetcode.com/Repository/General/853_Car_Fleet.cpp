// https://leetcode.com/problems/car-fleet/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    
    vector<pair<int, int>> cars (n); // pos, speed
    for (int i = 0; i < n; i++) {
      cars[i] = { position[i], speed[i] };
    }
    
    sort(cars.rbegin(), cars.rend());
    
    vector<double> carFleet;
    
    for (const auto& [ pos, speed ] : cars) {
      double hrs = (double)(target - pos) / speed;
      
      if (carFleet.size() == 0 or carFleet.back() < hrs)
        carFleet.emplace_back(hrs);
    }
    
    return carFleet.size();
  }
};