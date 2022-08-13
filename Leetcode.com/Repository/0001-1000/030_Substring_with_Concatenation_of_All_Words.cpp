// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> findSubstring(string& s, vector<string>& words) {
    int n = s.length(), each_len = words[0].length(), total_len = each_len * words.size();
    
    unordered_map<string, int> wordCount;
    for (const string& word : words) {
      wordCount[word]++;
    }
    
    unordered_map<string, int> subCount;
    vector<int> result;
    for (int i = 0; i < n - total_len + 1; i++) {
      subCount = {};
      string window = s.substr(i, total_len);
      
      int j;
      for (j = 0; j < total_len - each_len + 1; j += each_len) {
        string sub = window.substr(j, each_len);
        subCount[sub]++;
        if (wordCount.count(sub) == 0 or wordCount[sub] < subCount[sub])
          break;
      }
      
      if (j == window.length())
        result.emplace_back(i);
    }
    
    return result;
  }
};