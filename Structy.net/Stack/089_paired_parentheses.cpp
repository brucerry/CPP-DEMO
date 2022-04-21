#include <string>
using namespace std;

bool pairedParentheses(std::string str) {
  int count = 0;
  for (const char& ch : str) {
    if (ch == '(')
      count++;
    else if (ch == ')') {
      if (count == 0)
        return false;
      count--;
    }
  }
  return count == 0;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}