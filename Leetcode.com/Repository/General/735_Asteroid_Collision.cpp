// https://leetcode.com/problems/asteroid-collision/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result;
    
    for (int& ast : asteroids) {
      while (result.size() and result.back() > 0 and ast < 0) {
        int diff = result.back() + ast;
        
        if (diff > 0)
          ast = 0;
        else if (diff < 0)
          result.pop_back();
        else {
          ast = 0;
          result.pop_back();
        }
      }
      
      if (ast)
        result.emplace_back(ast);
    }
    
    return result;
  }
};