// https://leetcode.com/problems/number-of-matching-subsequences/

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// s = len of s
// n = size of words
// time: O(s * n)
// space: O(n)
class HashmapCharPtr {
public:
  int numMatchingSubseq(string& s, vector<string>& words) {
    unordered_map<string, int> wordCount;
    for (const string& word : words) {
      wordCount[word]++;
    }
    
    const char* ps = s.c_str();
    
    int match = 0;
    for (const auto& [ word, count ] : wordCount) {
      if (isSubseq(ps, word.c_str()))
        match += count;
    }
    
    return match;
  }
  
private:
  bool isSubseq(const char* s, const char* word) {
    int s_len = strlen(s), word_len = strlen(word);
    
    if (s_len < word_len)
      return false;
    
    int j = 0;
    for (int i = 0; i < s_len and j < word_len; i++) {
      if (s[i] == word[j])
        j++;
    }
    
    return j == word_len;
  }
};

// s = len of s
// n = size of words
// time: O(s * n)
// space: O(n)
class HashmapString {
public:
  int numMatchingSubseq(string& s, vector<string>& words) {
    unordered_map<string, int> wordCount;
    for (const string& word : words) {
      wordCount[word]++;
    }
    
    int match = 0;
    for (const auto& [ word, count ] : wordCount) {
      if (isSubseq(s, word))
        match += count;
    }
    
    return match;
  }
  
private:
  bool isSubseq(const string& s, const string& word) {
    int s_len = s.length(), word_len = word.length();
    
    if (s_len < word_len)
      return false;
    
    int j = 0;
    for (int i = 0; i < s_len and j < word_len; i++) {
      if (s[i] == word[j])
        j++;
    }
    
    return j == word_len;
  }
};