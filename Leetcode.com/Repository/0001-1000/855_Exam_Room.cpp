// https://leetcode.com/problems/exam-room/

#include <vector>
using namespace std;

// time: O(1) for constructor, O(n) for seat(), O(log(n)) for leave()
// space: O(n)

class ExamRoom {
public:
  ExamRoom(int n) {
    this->n = n;
  }
  
  int seat() {
    if (seats.size() == 0) {
      seats.emplace_back(0);
      return 0;
    }
    
    int maxDist = max(seats.front(), n - 1 - seats.back());
    for (int i = 0; i < seats.size() - 1; i++) {
      maxDist = max(maxDist, (seats[i+1] - seats[i]) / 2);
    }
    
    if (maxDist == seats.front()) {
      seats.emplace(seats.begin(), 0);
      return 0;
    }
    
    for (int i = 0; i < seats.size() - 1; i++) {
      if (maxDist == (seats[i+1] - seats[i]) / 2) {
        seats.emplace(seats.begin() + i + 1, (seats[i+1] + seats[i]) / 2);
        return seats[i+1];
      }
    }
    
    seats.emplace_back(n - 1);
    return n - 1;
  }
  
  void leave(int p) {
    for (int l = 0, r = seats.size() - 1; l <= r; ) {
      int m = l + (r - l) / 2;
      if (seats[m] == p) {
        seats.erase(seats.begin() + m);
        return;
      }
      else if (seats[m] < p)
        l = m + 1;
      else
        r = m - 1;
    }
  }
  
private:
  vector<int> seats;
  int n;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */