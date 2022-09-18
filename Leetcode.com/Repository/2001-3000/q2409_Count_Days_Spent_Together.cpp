// https://leetcode.com/problems/count-days-spent-together/

#include <string>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
  int countDaysTogether(string& arriveAlice, string& leaveAlice, string& arriveBob, string& leaveBob) {
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = 1; i < sizeof(days) / sizeof(int); i++) {
      days[i] += days[i-1];
    }
    
    int a1 = dateToDays(days, arriveAlice);
    int a2 = dateToDays(days, leaveAlice);
    int b1 = dateToDays(days, arriveBob);
    int b2 = dateToDays(days, leaveBob);
    
    int arrive = max(a1, b1);
    int leave = min(a2, b2);
    return max(0, leave - arrive + 1);
  }
  
private:
  int dateToDays(int* days, string& date) {
    int month = (date[0] - '0') * 10 + date[1] - '0';
    int day = (date[3] - '0') * 10 + date[4] - '0';
    return days[month-1] + day;
  }
};