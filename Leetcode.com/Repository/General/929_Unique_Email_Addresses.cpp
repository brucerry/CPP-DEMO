// https://leetcode.com/problems/unique-email-addresses/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// n = len of emails
// m = len of each email
// time: O(n * m)
// space: O(n)

class Solution {
public:
  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> uniqueEmails;
    
    for (const string& email : emails) {
      string simplified;
      
      int i = 0;
      while (email[i] != '+' and email[i] != '@') {
        if (email[i] != '.')
          simplified += email[i];
        i++;
      }
      
      i = email.find('@', i);
      simplified += email.substr(i);
      uniqueEmails.emplace(simplified);
    }
    
    return uniqueEmails.size();
  }
};