// https://leetcode.com/problems/maximum-number-of-eaten-apples/

#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    int n = apples.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // rot day, count of apples
    
    int eat = 0;
    for (int curDay = 0; curDay < n; curDay++) {
      while (minHeap.size() and minHeap.top().first <= curDay)
        minHeap.pop();
      
      if (days[curDay])
        minHeap.emplace(curDay + days[curDay], apples[curDay]);
      
      if (minHeap.size()) {
        auto [ rotDay, count ] = minHeap.top();
        minHeap.pop();
        eat++;
        if (--count)
          minHeap.emplace(rotDay, count);
      }
    }
    
    for (int curDay = n; minHeap.size();) {
      while (minHeap.size() and minHeap.top().first <= curDay)
        minHeap.pop();
      
      if (minHeap.size()) {
        auto [ rotDay, count ] = minHeap.top();
        minHeap.pop();
        int maxEat = rotDay - curDay;
        int canEat = min(maxEat, count);
		    curDay += canEat;
        eat += canEat;
      }
    }
    
    return eat;
  }
};