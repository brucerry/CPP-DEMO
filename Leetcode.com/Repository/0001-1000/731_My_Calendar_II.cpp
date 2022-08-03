// https://leetcode.com/problems/my-calendar-ii/

#include <map>
using namespace std;

// time: O(n)
// space: O(n)

class MyCalendarTwo {
public:
  MyCalendarTwo() {
    
  }
  
  bool book(int start, int end) {
    counts[start]++;
    counts[end]--;
    
    int ongoing = 0;
    for (const auto& [ _, count ] : counts) {
      ongoing += count;
      if (ongoing == 3) {
        if (--counts[start] == 0)
          counts.erase(start);
        if (++counts[end] == 0)
          counts.erase(end);
        return false;
      }
    }
    return true;
  }
  
private:
  map<int, int> counts; // timestamp, count
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */