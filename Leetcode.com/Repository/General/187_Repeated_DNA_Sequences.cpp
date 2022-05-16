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
    if (s.length() < 10)
      return {};
    
    unordered_set<string> DNAs;
    unordered_set<string> result;
    
    for (int i = 0; i < s.length() - 10 + 1; i++) {
      string dna = s.substr(i, 10);
      if (DNAs.count(dna))
        result.emplace(dna);
      
      DNAs.emplace(dna);
    }
    
    return vector<string>(result.begin(), result.end());
  }
};