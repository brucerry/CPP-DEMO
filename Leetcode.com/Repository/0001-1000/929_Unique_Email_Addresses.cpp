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
      int domainIndex = email.find('@');
      string localName;
      for (int i = 0; i < domainIndex and email[i] != '+'; i++) {
        if (email[i] != '.')
          localName += email[i];
      }
      uniqueEmails.insert(localName + email.substr(domainIndex));
    }
    return uniqueEmails.size();
  }
};