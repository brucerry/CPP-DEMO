// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/

#include <vector>
#include <string>
#include <array>
using namespace std;

// n = size of words
// w = len of each word
// time: O(n * (w + 26)) => O(n * w)
// space: O(26) => O(1)
class TwoPointers {
public:
  vector<string> removeAnagrams(vector<string>& words) {
    vector<string> result { words[0] };
    for (int l = 0, r = 1; r < words.size(); r++) {
      if (!isAnagram(words, words[l], words[r])) {
        result.emplace_back(words[r]);
        l = r;
      }
    }
    return result;
  }
  
private:
  bool isAnagram(vector<string>& words, string& s1, string& s2) {
    if (s1.length() != s2.length())
      return false;
    
    int count1[26] = {}, count2[26] = {};
    for (int i = 0; i < s1.length(); i++) {
      count1[s1[i] - 'a']++;
      count2[s2[i] - 'a']++;
    }
    
    return memcmp(count1, count2, sizeof(count1)) == 0;
  }
};

// n = size of words
// w = len of each word
// time: O(n * w + n * 26) => O(n * w)
// space: O(n * 26) => O(n)
class PreCountChar {
public:
  vector<string> removeAnagrams(vector<string>& words) {
    int n = words.size();
    vector<array<int, 26>> charCounts (n);
    for (int i = 0; i < n; i++) {
      for (const char& c : words[i])
        charCounts[i][c - 'a']++;
    }
    
    vector<string> result { words[0] };
    for (int l = 0, r = 1; r < n; r++) {
      if (charCounts[l] != charCounts[r]) {
        result.emplace_back(words[r]);
        l = r;
      }
    }
    return result;
  }
};