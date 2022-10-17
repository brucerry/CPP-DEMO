// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// time: O(n)
// space: O(n)

class Array {
public:
  int longestPalindrome(vector<string>& words) {
    int counts[26][26] {};
    for (const string& word : words) {
      counts[word[0] - 'a'][word[1] - 'a']++;
    }

    int asym = 0, sym = 0, bonus = 0;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (i == j) {
          if (counts[i][j] % 2) {
            sym += counts[i][j] - 1;
            bonus = 1;
          }
          else
            sym += counts[i][j];
        }
        else if (counts[j][i])
          asym += min(counts[i][j], counts[j][i]);
      }
    }

    return (asym + sym + bonus) * 2;
  }
};

class HashMap {
public:
  int longestPalindrome(vector<string>& words) {
    unordered_map<string, int> wordCount;
    for (const string& word : words) {
      wordCount[word]++;
    }

    int asym = 0, sym = 0, bonus = 0;
    for (const auto& [ word, count ] : wordCount) {
      string rev = string(1, word[1]) + word[0];
      if (word == rev) {
        if (count % 2) {
          sym += count - 1;
          bonus = 1;
        }
        else
          sym += count;
      }
      else if (wordCount.count(rev)) {
        asym += min(count, wordCount[rev]);
      }
    }

    return (asym + sym + bonus) * 2;
  }
};