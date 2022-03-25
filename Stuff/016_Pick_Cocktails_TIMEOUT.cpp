#include <iostream>
#include <vector>
using namespace std;

int findMedianOfThree(vector<int>& buffer, int left, int right, int mid) {
  if (buffer[mid] < buffer[left]) swap(buffer[mid], buffer[left]);
  if (buffer[right] < buffer[left]) swap(buffer[right], buffer[left]);
  if (buffer[mid] < buffer[right]) swap(buffer[mid], buffer[right]);
  return right;
}

int kthLowest(vector<int>& buffer, int l, int r, int k) {
  int medianOfThree = findMedianOfThree(buffer, l, r, l + ((r - l) >> 1));
  int pivot = buffer[medianOfThree];
  int p = l;

  for (int i = l; i < r; i++) {
    if (buffer[i] <= pivot) {
      swap(buffer[i], buffer[p]);
      p++;
    }    
  }
  swap(buffer[medianOfThree], buffer[p]);

  if (p > k) return kthLowest(buffer, l, p - 1, k);
  else if (p < k) return kthLowest(buffer, p + 1, r, k);
  else return buffer[p];
}

int kthLowest(vector<int> buffer, int k) {
  return kthLowest(buffer, 0, buffer.size() - 1, k);
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> cocktails (n);

  for (int i = 0; i < n; i++) {
    int score;
    cin >> score;
    cocktails[i] = score;

    if (i >= m - 1) {
      if (i - m + 1 > 0) cout << ' ';
      cout << kthLowest(vector<int>(cocktails.begin() + i - m + 1, cocktails.begin() + i + 1), k - 1);
    }
  }
}