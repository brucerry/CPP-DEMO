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
    unordered_map<char, int> charCount; // char, count
    for (const char& c : s)
      charCount[c]++;
    
    vector<pair<int, char>> buffer; // count, char
    for (const auto& [ c, count ] : charCount)
      buffer.emplace_back(count, c);
    sort(buffer.rbegin(), buffer.rend());
    
    string result;
    for (const auto& [ count, c ] : buffer) {
      result.append(count, c);
    }
    
    return result;
  }
};