#include <string>
using namespace std;

bool pairedParentheses(std::string str) {
  int count = 0;
  for (auto ch : str) {
    if (ch == '(') count++;
    else if (ch == ')') {
      if (count > 0) count--;
      else return false;
    }
  }
  return count == 0;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}