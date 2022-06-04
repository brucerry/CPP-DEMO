// https://leetcode.com/problems/jump-game-iii/

#include <vector>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    
    queue<int> queue; // index
    queue.emplace(start);
    arr[start] = -arr[start];
    
    while (queue.size()) {
      int i = queue.front();
      queue.pop();
      
      if (arr[i] == 0)
        return true;
      
      int leftIndex = i + arr[i];
      int rightIndex = i - arr[i];
      
      if (leftIndex >= 0 and arr[leftIndex] >= 0) {
        arr[leftIndex] = -arr[leftIndex];
        queue.emplace(leftIndex);
      }
      
      if (rightIndex < n and arr[rightIndex] >= 0) {
        arr[rightIndex] = -arr[rightIndex];
        queue.emplace(rightIndex);
      }
    }
    
    return false;
  }
};