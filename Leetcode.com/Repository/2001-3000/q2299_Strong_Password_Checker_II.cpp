// https://leetcode.com/problems/strong-password-checker-ii/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool strongPasswordCheckerII(string& password) {
    bool lowercase = false, uppercase = false, digit = false, special = false;
    for (int i = 0; i < password.size(); i++) {
      if (i and password[i-1] == password[i])
        return false;
      lowercase |= islower(password[i]);
      uppercase |= isupper(password[i]);
      digit |= isdigit(password[i]);
      special |= ispunct(password[i]);
    }
    return lowercase and uppercase and digit and special and password.size() >= 8;
  }
};