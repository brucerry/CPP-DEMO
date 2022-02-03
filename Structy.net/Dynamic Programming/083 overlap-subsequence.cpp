#include <string>
#include <unordered_map>
using namespace std;

int overlapSubsequence(string s1, string s2, int i1, int i2, unordered_map<string, int> &memo) {
  string key = to_string(i1) + ',' + to_string(i2);
  if (memo.count(key)) return memo[key];
  if (i1 == s1.length() || i2 == s2.length()) return 0;
  
  if (s1[i1] == s2[i2]) {
    memo[key] = 1 + overlapSubsequence(s1, s2, i1+1, i2+1, memo);
  } else {
    memo[key] = max(overlapSubsequence(s1, s2, i1+1, i2, memo), overlapSubsequence(s1, s2, i1, i2+1, memo));
  }
  
  return memo[key];
}

int overlapSubsequence(std::string s1, std::string s2) {
  unordered_map<string, int> memo;
  return overlapSubsequence(s1, s2, 0, 0, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}