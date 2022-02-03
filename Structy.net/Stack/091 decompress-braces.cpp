#include <string>
#include <vector>
using namespace std;

string repeatString(string str, int num) {
  string s;
  while (num--) {
    s += str;
  }
  return s;
}

std::string decompressBraces(std::string str) {
  string result;
  vector<string> vector;
  
  for (auto ch : str) {
    if (ch == '}') {
      string s = vector.back();
      vector.pop_back();
      while (!('0' <= vector.back()[0] && vector.back()[0] <= '9')) {
        s = vector.back() + s;
        vector.pop_back();
      }
      int num = vector.back()[0] - '0';
      vector.pop_back();
      vector.push_back(repeatString(s, num));
    } else if (ch != '{') {
      vector.push_back(string(1, ch));
    }
  }
  
  for (auto s : vector) {
    result += s;
  }
  
  return result;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}