// https://leetcode.com/problems/asteroid-collision/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    
    for (int& asteroid : asteroids) {
      while (ans.size() and ans.back() > 0 and asteroid < 0) {
        int diff = ans.back() + asteroid;
        
        if (diff > 0) {
          asteroid = 0;
        }
        else if (diff < 0) {
          ans.pop_back();
        }
        else {
          asteroid = 0;
          ans.pop_back();
        }
      }
      
      if (asteroid)
        ans.emplace_back(asteroid);
    }
    
    return ans;
  }
};