// https://leetcode.com/problems/find-the-k-beauty-of-a-number/

#include <string>
using namespace std;

// time: O(1)
// space: O(1)

class StringSolution {
public:
  int divisorSubstrings(int num, int k) {
    string s = to_string(num);
    int result = 0;
    for (int i = 0; i < s.size() - k + 1; i++) {
      int sub = stoi(s.substr(i, k));
      result += sub and num % sub == 0;
    }
    return result;
  }
};

class AvoidString {
public:
  int divisorSubstrings(int num, int k) {
    int result = 0, const_num = num, cur = 0, len = 0, pow = 1;
    for (; num; num /= 10) {
      cur += num % 10 * pow;
      len++;
      if (len >= k) {
        result += cur and const_num % cur == 0;
        cur /= 10;
      }
      else
        pow *= 10;
    }
    return result;
  }
};