// https://leetcode.com/problems/words-within-two-edits-of-dictionary/

#include <vector>
#include <string>
using namespace std;

// q = size of queries
// d = size of dictionary
// time: O(q * d * 100)
// space: O(1)

class Solution {
public:
  vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> result;
    for (const string& que : queries) {
      for (const string& dict : dictionary) {
        int edits = 0;
        for (int i = 0; i < que.size(); i++) {
          edits += que[i] != dict[i];
        }
        if (edits <= 2) {
          result.emplace_back(que);
          break;
        }
      }
    }
    return result;
  }
};