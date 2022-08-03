// https://leetcode.com/problems/my-calendar-iii/

#include <map>
using namespace std;

// time: O(n)
// space: O(n)

class MyCalendarThree {
public:
  MyCalendarThree() {
    
  }
  
  int book(int start, int end) {
    counts[start]++;
    counts[end]--;
    
    int ongoing = 0, k = 0;
    for (const auto& [ _, count ] : counts)
      k = max(k, ongoing += count);
    
    return k;
  }
  
private:
  map<int, int> counts; // timestamp, count
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */