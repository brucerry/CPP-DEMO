#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair {
  int num;
  int index; // input row index within k

  Pair(int num, int index)
    : num(num), index(index) {};

  int operator-(const Pair& other) const {
    return num - other.num;
  }

  bool operator<(const Pair& other) const {
    return num < other.num;
  }
};

int main() {
  int k, n, num;

  cin >> k;
  vector<Pair> nums;

  for (int i = 0; i < k; i++) {
    cin >> n;
    while (n--) {
      cin >> num;
      nums.emplace_back(num, i);
    }
  }

  sort(nums.begin(), nums.end());

  int minLeft = nums[0].num;
  int minRight = nums.back().num;
  int minRange = minRight - minLeft;
  int left = 0;
  int right = 0;
  
  vector<int> freq (k, 0);
  int total = 0;

  while (right < nums.size()) {
    freq[nums[right].index]++;
    if (freq[nums[right].index] == 1) total++;

    if (total == k) {
      while (left < right && freq[nums[left].index] > 1) {
        freq[nums[left].index]--;
        left++;
      }

      int range = nums[right] - nums[left];
      if (range < minRange) {
        minLeft = nums[left].num;
        minRight = nums[right].num;
        minRange = range;
      }

      freq[nums[left].index]--;
      left++;
      total--;
    }
    right++;
  }

  cout << minLeft << ' ' << minRight;
}