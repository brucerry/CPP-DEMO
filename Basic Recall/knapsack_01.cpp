#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int _01_knapsack(vector<int> weights, vector<int> values, int idx, int capacity, unordered_map<string, int> &memo)
{
  int numOfItems = weights.size();
  string tag = to_string(numOfItems) + ',' + to_string(capacity);
  if (memo.count(tag)) return memo[tag];
  if (capacity <= 0 || idx >= numOfItems) return 0;

  int maxValue = -1;

  for (int i = idx; i < numOfItems; i++)
  {
    int value = capacity >= weights[i] ?
                values[i] + _01_knapsack(weights, values, i + 1, capacity - weights[i], memo) :
                _01_knapsack(weights, values, i + 1, capacity, memo);

    if (maxValue == -1 || value > maxValue)
    {
      maxValue = value;
    }
  }

  memo[tag] = maxValue;
  return maxValue;
}

int main()
{
  vector<int> weights = {10,  20,  30, 31, 32, 33, 34, 45, 55,  65};
  vector<int> values =  {60, 100, 120,  1,  2,  3,  4,  5,  6, 777};
  int capacity = 88887777;
  unordered_map<string, int> memo;

  cout << _01_knapsack(weights, values, 0, capacity, memo);

  return 0;
}
