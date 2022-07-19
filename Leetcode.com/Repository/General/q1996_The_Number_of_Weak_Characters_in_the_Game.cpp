// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n + maxAttack)
// space: O(maxAttack)
class Greedy {
public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    int maxAttack = 0;
    for (const auto& p : properties) {
      maxAttack = max(maxAttack, p[0]);
    }
    
    vector<int> maxDefenses (maxAttack + 2);
    for (const auto& p : properties) {
      int attack = p[0];
      int defense = p[1];
      maxDefenses[attack] = max(maxDefenses[attack], defense);
    }
    
    for (int i = maxAttack; i >= 0; i--) {
      maxDefenses[i] = max(maxDefenses[i], maxDefenses[i+1]);
    }
    
    int weak = 0;
    for (const auto& p : properties) {
      int attack = p[0];
      int defense = p[1];
      if (maxDefenses[attack + 1] > defense)
        weak++;
    }
    
    return weak;
  }
};

// time: O(n * log(n))
// space: O(log(n)) for sorting
class Sorting {
public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end(), [](const auto& a, const auto& b) -> bool {
      return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });
    
    int weak = 0, maxDefense = 0;
    for (const auto& p : properties) {
      if (maxDefense > p[1])
        weak++;
      else
        maxDefense = p[1];
    }
    
    return weak;
  }
};