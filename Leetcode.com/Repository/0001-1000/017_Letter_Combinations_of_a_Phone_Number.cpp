// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// time: O(4^n)
// space: O(n)

class Solution {
public:
  vector<string> letterCombinations(string& digits) {
    unordered_map<char, string> numMap {
      { '2', "abc"  },
      { '3', "def"  },
      { '4', "ghi"  },
      { '5', "jkl"  },
      { '6', "mno"  },
      { '7', "pqrs" },
      { '8', "tuv"  },
      { '9', "wxyz" },
    };
    
    vector<string> solution;
    string comb;
    solve(digits, solution, comb, numMap, 0);
    return solution;
  }
  
private:
  void solve(string& digits, vector<string>& solution, string& comb, unordered_map<char, string>& numMap, int i) {
    if (digits.length() == 0)
      return;
    
    if (i == digits.length()) {
      solution.emplace_back(comb);
      return;
    }
    
    for (const char& letter : numMap[digits[i]]) {
      comb += letter;
      solve(digits, solution, comb, numMap, i + 1);
      comb.pop_back();
    }
  }
};