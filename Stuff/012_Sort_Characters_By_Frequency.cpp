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

  vector<pair<int, char>> buffer;

  for (auto& pair : charCount) {
    buffer.emplace_back(pair.second, pair.first);
  }

  sort(buffer.begin(), buffer.end(), [](const pair<int, char>& a, const pair<int, char>& b) -> bool {
    return a.first == b.first ? a.second < b.second : a.first > b.first;
  });

  string ans;

  for (auto& pair : buffer) {
    ans.append(pair.first, pair.second);
  }

  cout << ans;
}