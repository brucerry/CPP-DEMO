#include <vector>
#include <string>
using namespace std;

std::vector<std::string> parentheticalPossibilities(std::string str, int idx) {
  if (idx == str.length()) return {""};
  
  vector<string> result;
  int nextPos = idx + 1;
  string choices = string(1, str[idx]);
  
  if (str[idx] == '(') {
    nextPos = str.find(')', idx) + 1;
    choices = str.substr(idx + 1, nextPos - idx - 2);
  }
  
  for (auto suffix : parentheticalPossibilities(str, nextPos)) {
    for (auto ch : choices) {
      result.push_back(ch + suffix);
    }
  }
  
  return result;
}

std::vector<std::string> parentheticalPossibilities(std::string str) {
  return parentheticalPossibilities(str, 0);
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}