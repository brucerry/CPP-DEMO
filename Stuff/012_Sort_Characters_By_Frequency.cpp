#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  unordered_map<char, int> charCount;

  for (char& ch : s) {
    charCount[ch]++;
  }

  vector<pair<char, int>> buffer;

  for (auto& pair : charCount) {
    buffer.emplace_back(pair);
  }

  sort(buffer.begin(), buffer.end(), [](const pair<char, int>& a, const pair<char, int>& b) -> bool {
    return a.second == b.second ? a.first < b.first : a.second > b.second;
  });

  string ans;

  for (auto& pair : buffer) {
    ans.append(pair.second, pair.first);
    // ans += string(pair.second, pair.first);
  }

  cout << ans;
}