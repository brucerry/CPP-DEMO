// https://leetcode.com/problems/letter-combinations-of-a-phone-number/


#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
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

  vector<string> letterCombinations(string digits) {
    if (digits.length() == 0) return {};

    vector<string> subCombinations = letterCombinations(digits.substr(1));

    vector<string> result;
    
    if (subCombinations.size() == 0) {
      for (auto alphabet : mapping[digits[0]]) {
        result.push_back(alphabet);
      }
    } else {
      for (auto combo : subCombinations) {
        for (auto alphabet : mapping[digits[0]]) {
          string str = alphabet + combo;
          result.push_back(str);
        }
      }
    }

    return result;
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