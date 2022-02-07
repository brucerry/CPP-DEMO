#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool befittingBrackets(std::string str) {
  unordered_map<char, char> mapping = {
    {')', '('},
    {'}', '{'},
    {']', '['}
  };
  
  vector<char> vector;
  for (auto ch : str) {
    if (ch == '(' || ch == '{' || ch == '[') {
      vector.push_back(ch);
    } else {
      if (vector.size() == 0) return false;
      if (vector.back() == mapping[ch]) vector.pop_back();
      else return false;
    }
  }
  
  return vector.size() == 0;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}