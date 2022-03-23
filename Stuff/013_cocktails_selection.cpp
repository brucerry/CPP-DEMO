#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findClosestPosition(vector<pair<int, int>>& cocktails, int pos, int left, int right) {
  if (left < right) {
    int mid = left + ((right - left) >> 1);

    if (cocktails[mid].second == pos) return pos;

    int leftClosest = findClosestPosition(cocktails, pos, left, mid);
    if (leftClosest == pos) return pos;
    int rightClosest = findClosestPosition(cocktails, pos, mid+1, right);
    if (rightClosest == pos) return pos;

    int leftDiff = abs(leftClosest - pos);
    int rightDiff = abs(rightClosest - pos);

    if (leftDiff < rightDiff) {
      return leftClosest;
    }
    else if (leftDiff > rightDiff) {
      return rightClosest;
    }
    else {
      if (leftClosest < rightClosest) {
        return leftClosest;
      }
      else {
        return rightClosest;
      }
    }
  }
  return cocktails[left].second;
}

int main() {
  int n, q;
  cin >> n >> q;

  vector<pair<int, int>> cocktails (n); // concentration, set of position
  vector<pair<int, int>> judges (q); // min-concentration, position

  for (int i = 0; i < n; i++) {
    int position, concentration;
    cin >> position >> concentration;
    cocktails[i] = {concentration, position};
  }

  for (int i = 0; i < q; i++) {
    int position, minConcentration;
    cin >> position >> minConcentration;
    judges[i] = {minConcentration, position};
  }
  
  sort(cocktails.begin(), cocktails.end());

  for (int i = 0; i < q; i++) {
    int start = distance(cocktails.begin(), lower_bound(cocktails.begin(), cocktails.end(), make_pair(judges[i].first, 0)));
    if (start == cocktails.size()) {
      cout << -1;
    }
    else {
      cout << findClosestPosition(cocktails, judges[i].second, start, cocktails.size() - 1);
    }
    cout << endl;
  }
}