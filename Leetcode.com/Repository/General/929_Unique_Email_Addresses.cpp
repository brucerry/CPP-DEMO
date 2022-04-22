// https://leetcode.com/problems/unique-email-addresses/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> emailSet;
    
    for (const string& email : emails) {
      string simplifiedEmail;
      int i = 0;
      while (email[i] != '+' && email[i] != '@') {
        if (email[i] != '.')
          simplifiedEmail += email[i];
        i++;
      }
      
      i = email.find('@', i);
      
      simplifiedEmail += email.substr(i);
      
      emailSet.emplace(simplifiedEmail);
    }
    
    return emailSet.size();
  }
};