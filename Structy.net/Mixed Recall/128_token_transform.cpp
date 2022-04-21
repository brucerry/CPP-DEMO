#include <unordered_map>
#include <string>
using namespace std;

std::string tokenTransform(std::string s, std::unordered_map<std::string, std::string> tokens) {
  if (tokens.count(s)) return tokens[s];
  string result;
  
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != '$') {
      result += s[i];
    } else {
      int end = s.find('$', i + 1);
      const string& key = s.substr(i, end - i + 1);
      const string& token = tokenTransform(tokens[key], tokens);
      tokens[key] = token;
      result += token;
      i = end;
    }
  }
  
  return result;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}