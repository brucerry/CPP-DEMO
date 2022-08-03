// https://leetcode.com/problems/my-calendar-i/

#include <map>
using namespace std;

// time: O(log(n))
// space: O(n)

class MyCalendar {
public:
  MyCalendar() {
    
  }
  
  // method 1:
  bool book(int start, int end) {
    auto next = booked.lower_bound(start);
    if (next != booked.end() and next->first < end)
      return false;
    if (next != booked.begin() and start < (--next)->second)
      return false;
    booked[start] = end;
    return true;
  }

  // method 2:
  bool book(int start, int end) {
    auto next = booked.upper_bound(start);
    if (next != booked.end() and next->second < end)
      return false;
    booked[end] = start;
    return true;
  }
  
private:
  map<int, int> booked; // start, end
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */