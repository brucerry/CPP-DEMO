#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int quickestConcat(std::string str, std::vector<std::string> words, int i, unordered_map<int, int> &memo) {
  if (memo.count(i)) return memo[i];
  if (i == str.length()) return 0;
  
  int min = -1;
  for (auto word : words) {
    int pos = str.find(word, i);
    if (pos == i) {
      int count = quickestConcat(str, words, i + word.length(), memo);
      if (count != -1) {
        count++;
        if (min == -1 || min > count) {
          min = count;
        }
      }
    }
  }
  
  memo[i] = min;
  return min;
}

int quickestConcat(std::string str, std::vector<std::string> words) {
  unordered_map<int, int> memo;
  return quickestConcat(str, words, 0, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}