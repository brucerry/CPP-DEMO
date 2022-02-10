#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool lexicalOrder(std::string word1, std::string word2, std::string alphabet) {
  int len = max(word1.length(), word2.length());
  
  for (int i = 0; i < len; i++) {
    int index1 = find(alphabet.begin(), alphabet.end(), word1[i]) - alphabet.begin();
    int index2 = find(alphabet.begin(), alphabet.end(), word2[i]) - alphabet.begin();
    int val1 = index1 < alphabet.length() ? index1 : -1;
    int val2 = index2 < alphabet.length() ? index2 : -1;
    if (val1 < val2) return true;
    if (val1 > val2) return false;
  }
  
  return true;
}

bool detectDictionary(std::vector<std::string> dictionary, std::string alphabet) {
  for (int i = 0; i < dictionary.size() - 1; i++) {
    if (!lexicalOrder(dictionary[i], dictionary[i+1], alphabet)) return false;
  }
  return true;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}