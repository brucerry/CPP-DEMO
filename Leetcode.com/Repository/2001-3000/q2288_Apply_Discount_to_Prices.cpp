// https://leetcode.com/problems/apply-discount-to-prices/

#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  string discountPrices(string& sentence, int discount) {
    double dis = 1.0 - discount / 100.0;
    
    stringstream ss (sentence);
    string s, result;
    while (ss >> s) {
      result += applyDiscount(s, dis) + ' ';
    }
    result.pop_back();
    return result;
  }
  
private:
  string applyDiscount(string& s, double discount) {
    if (s[0] != '$' or s.length() == 1)
      return s;
    
    double price = 0;
    for (int i = 1; i < s.length(); i++) {
      if (!isdigit(s[i]))
        return s;
      price = price * 10 + s[i] - '0';
    }
    
    stringstream ss;
    ss << fixed << setprecision(2) << price * discount;
    return '$' + ss.str();
  }
};