// https://leetcode.com/problems/course-schedule-iii/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
      return a[1] < b[1];
    });
    
    priority_queue<int> maxHeap; // duration
    int curDay = 0;
    for (const auto& course : courses) {
      int duration = course[0];
      int lastDay = course[1];
      if (curDay + duration <= lastDay) {
        maxHeap.emplace(duration);
        curDay += duration;
      }
      else if (maxHeap.size() and maxHeap.top() > duration) {
        curDay += duration - maxHeap.top();
        maxHeap.pop();
        maxHeap.emplace(duration);
      }
    }
    
    return maxHeap.size();
  }
};