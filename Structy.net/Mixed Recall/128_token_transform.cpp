#include <unordered_map>
#include <string>
using namespace std;

std::string tokenTransform(std::string s, std::unordered_map<std::string, std::string> tokens, unordered_map<string, string>& memo) {
  if (memo.count(s)) return memo[s];
  string result;
  
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != '$') {
      result += s[i];
    } else {
      int end = s.find('$', i + 1);
      string token = s.substr(i, end - i + 1);
      result += tokenTransform(tokens[token], tokens, memo);
      i = end;
    }
  }
  
  memo[s] = result;
  return result;
}

std::string tokenTransform(std::string s, std::unordered_map<std::string, std::string> tokens) {
  unordered_map<string, string> memo;
  return tokenTransform(s, tokens, memo);
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}