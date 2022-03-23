// https://leetcode.com/problems/sort-characters-by-frequency/

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  string frequencySort(string& s) {
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
      ans += string(pair.second, pair.first);
    }

    return ans;
  }
};