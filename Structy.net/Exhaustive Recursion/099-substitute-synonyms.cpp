#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

vector<string> buildWords(string sentence) {
  vector<string> result;
  stringstream ss (sentence);
  string s;
  while (getline(ss, s, ' ')) {
    result.push_back(s);
  }
  return result;
}

string joinWords(vector<string> words) {
  string result (words[0]);
  for (int i = 1; i < words.size(); i++) {
    result += ' ' + words[i];
  }
  return result;
}

vector<vector<string>> substituteSynonyms(vector<string> words,
                                            std::unordered_map<std::string, std::vector<std::string>> synonyms,
                                           int idx) {
  if (idx == words.size()) return {{}};
  
  string currentWord = words[idx];
  vector<vector<string>> suffixes = substituteSynonyms(words, synonyms, idx + 1);
  
  vector<vector<string>> result;
  
  if (synonyms.count(currentWord)) {
    for (auto sub : synonyms[currentWord]) {
      for (auto suffix : suffixes) {
        suffix.insert(suffix.begin(), sub);
        result.push_back(suffix);
      }
    }
  } else {
    for (auto suffix : suffixes) {
      suffix.insert(suffix.begin(), currentWord);
      result.push_back(suffix);
    }
  }
  
  return result;
}

std::vector<std::string> substituteSynonyms(std::string sentence, std::unordered_map<std::string, std::vector<std::string>> synonyms) {
  vector<string> words = buildWords(sentence);
  vector<vector<string>> wordsOfAllSentences = substituteSynonyms(words, synonyms, 0);
  vector<string> result;
  for (auto words : wordsOfAllSentences) {
    result.push_back(joinWords(words));
  }
  return result;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}