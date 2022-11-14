// https://leetcode.com/problems/bulls-and-cows/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string getHint(string secret, string guess) {
    int a = 0, b = 0, n = secret.size();
    int counts[2][10] {};
    for (int i = 0; i < n; i++) {
      int s = secret[i] - '0', g = guess[i] - '0';
      if (s == g) {
        a++;
      }
      else {
        counts[0][s]++;
        counts[1][g]++;
      }
    }
    for (int i = 0; i < 10; i++) {
      b += min(counts[0][i], counts[1][i]);
    }
    return to_string(a) + "A" + to_string(b) + "B";
  }
};