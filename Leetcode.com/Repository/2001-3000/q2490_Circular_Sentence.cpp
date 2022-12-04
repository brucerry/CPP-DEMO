// https://leetcode.com/problems/circular-sentence/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool isCircularSentence(string sentence) {
    for (int i = 0; i < sentence.size(); i++) {
      if (sentence[i] == ' ' and sentence[i-1] != sentence[i+1])
        return false;
    }
    return sentence.front() == sentence.back();
  }
};