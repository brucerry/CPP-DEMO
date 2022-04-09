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
    vector<pair<int, int>> groups (position.size());
    
    for (int i = 0; i < position.size(); i++) {
      groups[i] = { position[i], speed[i] };
    }
    
    sort(groups.rbegin(), groups.rend());
    
    stack<float> stack;
    
    for (const auto& [ pos, spd ] : groups) {
      float timeNeeded = (float)(target - pos) / spd;
      
      if (stack.size() == 0 || stack.top() < timeNeeded)
        stack.emplace(timeNeeded);
    }
    
    return stack.size();
  }
};