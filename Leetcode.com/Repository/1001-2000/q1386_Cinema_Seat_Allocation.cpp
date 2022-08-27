// https://leetcode.com/problems/cinema-seat-allocation/

#include <vector>
#include <unordered_map>
using namespace std;

// s = size of reservedSeats
// time: O(s)
// space: O(s)

class Solution {
public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, int> rowReserved; // row, reserved
    for (const auto& rs : reservedSeats) {
      int row = rs[0], seat = rs[1];
      if (2 <= seat and seat <= 9)
        rowReserved[row] |= 1 << seat;
    }
    
    int groups = 2 * n;
    int seat_2to5 = 0b111100, seat_6to9 = 0b1111000000, seat_4to7 = 0b11110000;
    
    for (const auto& [ _, reserved ] : rowReserved) {
      bool reserved_2to5 = reserved & seat_2to5;
      bool reserved_4to7 = reserved & seat_4to7;
      bool reserved_6to9 = reserved & seat_6to9;
      groups -= reserved_2to5 and reserved_4to7 and reserved_6to9 ? 2 : 1;
    }
    
    return groups;
  }
};