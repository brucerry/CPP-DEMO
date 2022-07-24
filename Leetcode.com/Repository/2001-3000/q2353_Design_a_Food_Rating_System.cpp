// https://leetcode.com/problems/design-a-food-rating-system/

#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

// time: O(n * log(n)) for constructor, O(log(n)) for changeRating(), O(1) for highestRated()
// space: O(n)

class FoodRatings {
public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    int n = foods.size();
    for (int i = 0; i < n; i++) {
      string& food = foods[i];
      string& type = cuisines[i];
      int rating = ratings[i];
      foodRating[food] = { rating, type };
      typeNames[type].emplace(rating, food);
    }
  }
  
  void changeRating(string food, int newRating) {
    auto [ rating, type ] = foodRating[food];
    foodRating[food] = { newRating, type };
    typeNames[type].erase({ rating, food });
    typeNames[type].emplace(newRating, food);
  }
  
  string highestRated(string cuisine) {
    return typeNames[cuisine].begin()->second;
  }
  
private:
  struct cmp {
    bool operator() (const pair<int, string>& a, const pair<int, string>& b) const {
      return a.first == b.first ? a.second < b.second : a.first > b.first;
    }
  };
  
  unordered_map<string, pair<int, string>> foodRating; // food name, (rating, type)
  unordered_map<string, set<pair<int, string>, cmp>> typeNames; // type, (rating, food name)
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */