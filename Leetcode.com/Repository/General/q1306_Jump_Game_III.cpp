// https://leetcode.com/problems/jump-game-iii/

#include <vector>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    queue<int> queue; // index
    queue.emplace(start);
    arr[start] = -arr[start];
    
    while (queue.size()) {
      int i = queue.front();
      queue.pop();
      
      if (arr[i] == 0)
        return true;
      
      int l = i + arr[i];
      int r = i - arr[i];
      if (l >= 0 and arr[l] >= 0) {
        queue.emplace(l);
        arr[l] = -arr[l];
      }
      if (r < arr.size() and arr[r] >= 0) {
        queue.emplace(r);
        arr[r] = -arr[r];
      }
    }
    return false;
  }
};