// https://leetcode.com/problems/repeated-dna-sequences/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string& s) {
    int n = s.length();
    unordered_set<string> DNAs, repeated;
    for (int i = 0; i < n - 10 + 1; i++) {
      string dna = s.substr(i, 10);
      if (DNAs.count(dna) and repeated.count(dna) == 0)
        repeated.insert(dna);
      DNAs.insert(dna);
    }
    return vector<string>(repeated.begin(), repeated.end());
  }
};