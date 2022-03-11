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
    priority_queue<pair<int, char>> pq;
    if (a > 0) pq.push({a, 'a'});
    if (b > 0) pq.push({b, 'b'});
    if (c > 0) pq.push({c, 'c'});

    string ans;

    while (pq.size()) {
      auto [ count, ch ] = pq.top();
      pq.pop();

      if (ans.length() >= 2 && ch == ans[ans.size() - 1] && ch == ans[ans.size() - 2]) {
        if (pq.size() == 0) break;
        
        int nextCount = pq.top().first;
        char nextCh = pq.top().second;
        pq.pop();

        ans += nextCh;
        nextCount--;
        if (nextCount > 0) pq.push({nextCount, nextCh});
      }
      else {
        ans += ch;
        count--;
      }

      if (count > 0) pq.push({count, ch});
    }

    return ans;
  }
};