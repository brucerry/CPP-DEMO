// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// time: O(n * 4^n)
// space: O(n)

class Solution {
private:  
  void solve(string& digits, unordered_map<char, string>& mapping, vector<string>& ans, string& candidate, int i) {
    if (i == digits.length()) {
      ans.emplace_back(candidate);
      return;
    }
    
    for (const char& letter : mapping[digits[i]]) {
      candidate += letter;
      solve(digits, mapping, ans, candidate, i + 1);
      candidate.pop_back();
    }
  }

public:
   vector<string> letterCombinations(string digits) {
     unordered_map<char, string> mapping {
       { '2', "abc"  },
       { '3', "def"  },
       { '4', "ghi"  },
       { '5', "jkl"  },
       { '6', "mno"  },
       { '7', "pqrs" },
       { '8', "tuv"  },
       { '9', "wxyz" }
     };
     
     vector<string> ans;
     string candidate;
     
     if (digits.size())
       solve(digits, mapping, ans, candidate, 0);
     
     return ans;
   }
};