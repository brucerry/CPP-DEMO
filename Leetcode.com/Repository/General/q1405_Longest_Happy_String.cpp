// https://leetcode.com/problems/longest-happy-string/

#include <queue>
#include <string>
using namespace std;

// n = a + b + c
// time: O(n)
// space: O(1)

class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int, char>> maxHeap;
    if (a)
      maxHeap.emplace(a, 'a');
    if (b)
      maxHeap.emplace(b, 'b');
    if (c)
      maxHeap.emplace(c, 'c');
    
    string happy;
    while (maxHeap.size()) {
      auto [ count, ch ] = maxHeap.top();
      maxHeap.pop();
      
      if (happy.length() >= 2 and ch == happy.back() and ch == happy[happy.length() - 2]) {
        if (maxHeap.size() == 0)
          break;
        
        auto [ nextCount, nextCh ] = maxHeap.top();
        maxHeap.pop();
        
        happy += nextCh;
        if (--nextCount)
          maxHeap.emplace(nextCount, nextCh);
      }
      
      happy += ch;
      if (--count)
        maxHeap.emplace(count, ch);
    }
    
    return happy;
  }
};