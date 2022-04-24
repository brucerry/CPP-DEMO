#include <string>
#include <vector>
#include <climits>
using namespace std;

int quickestConcat(std::string str, std::vector<std::string> words) {
  vector<int> dp (str.length() + 1, INT_MAX);
  dp.back() = 0;
  
  for (int i = str.length() - 1; i >= 0; i--) {
    for (const string& word : words) {
      if (i == str.find(word, i) and dp[i + word.length()] != INT_MAX) {
        dp[i] = min(dp[i], 1 + dp[i + word.length()]);
      }
    }
  }
  
  return dp[0] == INT_MAX ? -1 : dp[0];
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}