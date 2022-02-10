#include <vector>
#include <string>
#include <iostream>
using namespace std;

void genParentheses(int n, int open, int close, string output, vector<string> &result) {
  if (close == n) {
    result.push_back(output);
    return;
  }

  if (open < n) {
    genParentheses(n, open + 1, close, output + '(', result);
  }

  if (close < open) {
    genParentheses(n, open, close + 1, output + ')', result);
  }
}

vector<string> genParentheses(int n) {
  vector<string> result;
  genParentheses(n, 0, 0, "", result);
  return result;
}

int main() {
  for (auto output : genParentheses(3)) {
    cout << output << endl;
  }
}