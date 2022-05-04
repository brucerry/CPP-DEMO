// https://leetcode.com/problems/seat-reservation-manager/

#include <queue>
using namespace std;

// time: O(n * log(n)) for constructor, O(log(n)) for reserve() & unreserve()
// space: O(n)

class SeatManager {
public:
  SeatManager(int n) {
    for (int seat = 1; seat <= n; seat++) {
      unreserved.emplace(seat);
    }
  }
  
  int reserve() {
    int seat = unreserved.top();
    unreserved.pop();
    return seat;
  }
  
  void unreserve(int seatNumber) {
    unreserved.emplace(seatNumber);
  }
  
private:
  priority_queue<int, vector<int>, greater<>> unreserved;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */