// https://leetcode.com/problems/count-integers-in-intervals/

#include <map>
using namespace std;

// time: O(1) for constructor and count(), Amortized O(log(n)) for add()
// space: O(n)

class CountIntervals {
public:
  CountIntervals() : numberOfIntegers(0) {
    
  }
  
  void add(int left, int right) {
    auto it = intervals.upper_bound(left);
    if (it != intervals.begin() and left <= prev(it)->second)
      it--;
    
    for (; it != intervals.end() and it->first <= right; it = intervals.erase(it)) {
      left = min(left, it->first);
      right = max(right, it->second);
      numberOfIntegers -= it->second - it->first + 1;
    }

    numberOfIntegers += right - left + 1;
    intervals[left] = right;
  }
  
  int count() {
    return numberOfIntegers;
  }

private:
  int numberOfIntegers;
  map<int, int> intervals; // left, right
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */