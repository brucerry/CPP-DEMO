/*
  using HashMap comparison

  n1 = length of s1
  n2 = length of s2

  time: O(max(n1, n2))
  space: O(max(n1, n2))
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> charCount(string s) {
  unordered_map<char, int> count;
  for (auto ch : s) {
    count[ch]++;
  }
  return count;
}

bool isAnagram(string s1, string s2) {
  return charCount(s1) == charCount(s2);
}

int main() {
  cout << isAnagram("bookg", "mary") << endl; // false
  cout << isAnagram("danger", "garden") << endl; // true
  cout << isAnagram("dangers", "garden") << endl; // false
  cout << isAnagram("dangerggf", "fggardegn") << endl; // true
  cout << isAnagram("aaaaaaaaaaaaaaassssssssssssssssssddddd", "dddddssssssssssssssssssaaaaaaaaaaaaaaa") << endl; // true
  cout << isAnagram("aaaaaaaaaaaaaaassssssssssssFssssssddddd", "dddddssssssssssssssssssaaaaaaaaaaaaaaa") << endl; // false
}
