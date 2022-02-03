#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool canConcat(string str, vector<string> words, int i, unordered_map<int, int> &memo) {
  if (memo.count(i)) return memo[i];
  if (i == str.length()) return true;
  
  for (auto word : words) {
    int pos = str.find(word, i);
    if (pos == i) {
      if (canConcat(str, words, i + word.length(), memo)) {
        memo[i] = true;
        return true;
      }
    }
  }
  
  memo[i] = false;
  return false;
}


bool canConcat(std::string str, std::vector<std::string> words) {
  unordered_map<int, int> memo;
  return canConcat(str, words, 0, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}