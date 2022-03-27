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

    vector<pair<int, char>> buffer;

    for (auto& pair : charCount) {
      buffer.emplace_back(pair.second, pair.first);
    }

    sort(buffer.rbegin(), buffer.rend());

    string ans;

    for (auto& pair : buffer) {
      ans.append(pair.first, pair.second);
    }

    return ans;
  }
};