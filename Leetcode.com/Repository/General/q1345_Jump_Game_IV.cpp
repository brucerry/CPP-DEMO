// https://leetcode.com/problems/jump-game-iv/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int minJumps(vector<int>& arr) {
    int n = arr.size();
    
    unordered_map<int, vector<int>> valIndices; // val, indices
    for (int i = 1; i < n; i++) {
      valIndices[arr[i]].emplace_back(i);
    }
    
    vector<char> visited (n);
    visited[0] = 1;
    
    queue<pair<int, int>> queue; // index, val
    queue.emplace(0, arr[0]);
    
    int step = 0;
    while (queue.size()) {
      int size = queue.size();
      
      while (size--) {
        auto [ index, val ] = queue.front();
        queue.pop();
        
        if (index == n - 1)
          return step;
        
        for (const int& i : valIndices[val]) {
          if (visited[i] == 0) {
            visited[i] = 1;
            queue.emplace(i, val);
          }
        }
        valIndices[val].clear();
        
        if (index - 1 >= 0 and visited[index - 1] == 0) {
          visited[index - 1] = 1;
          queue.emplace(index - 1, arr[index - 1]);
        }
        
        if (index + 1 < n and visited[index + 1] == 0) {
          visited[index + 1] = 1;
          queue.emplace(index + 1, arr[index + 1]);
        }
      }
      step++;
    }
    
    return -1;
  }
};