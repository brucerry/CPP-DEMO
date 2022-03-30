// https://leetcode.com/problems/asteroid-collision/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result;

    for (int& asteroid : asteroids) {
      while (result.size() && result.back() > 0 && asteroid < 0) {
        int diff = result.back() + asteroid;
        if (diff > 0) {
          asteroid = 0;
        }
        else if (diff < 0) {
          result.pop_back();
        }
        else {
          asteroid = 0;
          result.pop_back();
        }
      }
      
      if (asteroid) result.emplace_back(asteroid);
    }

    return result;
  }
};