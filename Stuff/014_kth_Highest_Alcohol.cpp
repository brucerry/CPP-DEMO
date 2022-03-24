#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findMedianOfThree(vector<pair<float, string>>& cocktails, int left, int right, int mid)
{
  if (cocktails[mid].first < cocktails[left].first) swap(cocktails[mid], cocktails[left]);
  if (cocktails[right].first < cocktails[left].first) swap(cocktails[right], cocktails[left]);
  if (cocktails[mid].first < cocktails[right].first) swap(cocktails[mid], cocktails[right]);
  return right;
}

string kthLargest(vector<pair<float, string>>& cocktails, int left, int right, int k) {
  int medianOfThree = findMedianOfThree(cocktails, left, right, left + ((right - left) >> 1));
  float pivot = cocktails[medianOfThree].first;
  int p = left;

  for (int i = left; i < right; i++) {
    if (cocktails[i].first <= pivot) {
      swap(cocktails[i], cocktails[p]);
      p++;
    }    
  }
  swap(cocktails[medianOfThree], cocktails[p]);

  if (p > k) return kthLargest(cocktails, left, p - 1, k);
  else if (p < k) return kthLargest(cocktails, p + 1, right, k);
  else return cocktails[p].second;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<float, string>> cocktails (n);

  for (int i = 0; i < n; i++) {
    float a, b, c;
    string name;
    cin >> a >> b >> c >> name;
    cocktails[i] = { c / (a + b + c), name };
  }

  cout << kthLargest(cocktails, 0, n - 1, n - k);
}