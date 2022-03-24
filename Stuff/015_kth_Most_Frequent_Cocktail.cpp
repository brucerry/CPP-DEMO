#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string kthMostFrequent(vector<pair<int, string>>& cocktails, int left, int right, int k) {
  pair<int, string>& pivot = cocktails[right];
  int p = left;

  for (int i = left; i < right; i++) {
    if ((cocktails[i].first < pivot.first) || (cocktails[i].first == pivot.first && !lexicographical_compare(cocktails[i].second.begin(), cocktails[i].second.end(), pivot.second.begin(), pivot.second.end()))) {
      swap(cocktails[i], cocktails[p]);
      p++;
    }
  }
  swap(cocktails[p], cocktails[right]);

  if (p > k) return kthMostFrequent(cocktails, left, p - 1, k);
  else if (p < k) return kthMostFrequent(cocktails, p + 1, right, k);
  else return cocktails[p].second;
}

int main() {
  int n, k;
  cin >> n >> k;

  unordered_map<string, int> nameCount;

  while (n--) {
    string name;
    cin >> name;
    nameCount[name]++;
  }

  vector<pair<int, string>> cocktails;

  for (auto& [ name, count ] : nameCount) {
    cocktails.emplace_back(make_pair(count, name));
  }

  cout << kthMostFrequent(cocktails, 0, cocktails.size() - 1, cocktails.size() - k);
}