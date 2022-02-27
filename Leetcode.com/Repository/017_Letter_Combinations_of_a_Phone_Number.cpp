// https://leetcode.com/problems/letter-combinations-of-a-phone-number/


#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
  vector<string> letterCombinations(string& digits, int idx, unordered_map<char, vector<string>>& mapping) {
    if (idx == digits.length()) return {};

    vector<string> subCombinations = letterCombinations(digits, idx + 1, mapping);

    vector<string> result;
    
    if (subCombinations.size() == 0) {
      for (auto& alphabet : mapping[digits[idx]]) {
        result.push_back(alphabet);
      }
    } else {
      for (auto& combo : subCombinations) {
        for (auto& alphabet : mapping[digits[idx]]) {
          result.push_back(alphabet + combo);
        }
      } 
    }

    return result;
  }

public:
   vector<string> letterCombinations(string digits) {
     unordered_map<char, vector<string>> mapping = {
      {'2', {"a","b","c"}},
      {'3', {"d","e","f"}},
      {'4', {"g","h","i"}},
      {'5', {"j","k","l"}},
      {'6', {"m","n","o"}},
      {'7', {"p","q","r","s"}},
      {'8', {"t","u","v"}},
      {'9', {"w","x","y","z"}}
    };
     return letterCombinations(digits, 0, mapping);
   }
};


// class Solution {
// public:
//   unordered_map<char, vector<string>> mapping = {
//     {'2', {"a","b","c"}},
//     {'3', {"d","e","f"}},
//     {'4', {"g","h","i"}},
//     {'5', {"j","k","l"}},
//     {'6', {"m","n","o"}},
//     {'7', {"p","q","r","s"}},
//     {'8', {"t","u","v"}},
//     {'9', {"w","x","y","z"}}
//   };

//   void letterCombinations(string digits, vector<string>& result, int idx, string currentStr) {
//     if (idx == digits.length()) {
//       result.push_back(currentStr);
//       return;
//     }

//     for (auto alphabet : mapping[digits[idx]]) {
//       letterCombinations(digits, result, idx + 1, currentStr + alphabet);
//     }
//   }

//   vector<string> letterCombinations(string digits) {
//     if (digits.length() == 0) return {};
//     vector<string> result;
//     letterCombinations(digits, result, 0, "");
//     return result;
//   }
// };