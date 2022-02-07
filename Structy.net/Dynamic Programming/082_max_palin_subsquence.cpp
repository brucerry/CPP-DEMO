#include <string>
#include <unordered_map>
using namespace std;

int maxPalinSubsequence(string s, int head, int tail, unordered_map<string, int> &memo) {
  string key = to_string(head) + ',' + to_string(tail);
  if (memo.count(key)) return memo[key];
  if (head == tail) return 1;
  if (head > tail) return 0;
  
  if (s[head] == s[tail]) {
    memo[key] = 2 + maxPalinSubsequence(s, head+1, tail-1, memo);
  } else {
    memo[key] = max(maxPalinSubsequence(s, head+1, tail, memo), maxPalinSubsequence(s, head, tail-1, memo));
  }
  
  return memo[key];
}

int maxPalinSubsequence(std::string s) {
  unordered_map<string, int> memo;
  return maxPalinSubsequence(s, 0, s.size() - 1, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}