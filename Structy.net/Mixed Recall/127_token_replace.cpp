#include <unordered_map>
#include <string>
using namespace std;

std::string tokenReplace(std::string s, std::unordered_map<std::string, std::string> tokens) {
  string result;
  
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != '$') {
      result += s[i];
    } else {
      int end = s.find('$', i + 1);
      string token = s.substr(i, end - i + 1);
      result += tokens[token];
      i = end;
    }
  }
  
  return result;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}