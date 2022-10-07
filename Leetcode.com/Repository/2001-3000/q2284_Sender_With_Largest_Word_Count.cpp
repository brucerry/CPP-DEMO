// https://leetcode.com/problems/sender-with-largest-word-count/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// n = size of messages
// m = len of messages[i]
// s = len of senders[i]
// time: O(n * m)
// space: O(n * s)

class Solution {
public:
  string largestWordCount(vector<string>& messages, vector<string>& senders) {
    int n = messages.size();
    
    unordered_map<string, int> nameWordcount;
    for (int i = 0; i < n; i++) {
      string& msg = messages[i];
      string& name = senders[i];
      nameWordcount[name] += count(msg.begin(), msg.end(), ' ') + 1;
    }

    string result;
    int largest = 0;
    for (const auto& [ name, wcount ] : nameWordcount) {
      if (wcount > largest or (wcount == largest and name > result)) {
        largest = wcount;
        result = name;
      }
    }

    return result;
  }
};