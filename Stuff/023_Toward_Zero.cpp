#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;

  cin >> n;

  vector<int> nums (n);

  int sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    sum += nums[i];
  }

  vector<char> dp ((sum << 1) + 1, 0); // range from -sum to sum

  // sum is the index of array half
  dp[sum + nums[0]]++;
  dp[sum - nums[0]]++;

  for (int i = 1; i < nums.size(); i++) {
    vector<char> cur ((sum << 1) + 1, 0);
    for (int s = -sum; s <= sum; s++) {
      if (dp[sum + s]) {
        cur[sum + s - nums[i]]++;
        cur[sum + s + nums[i]]++;
      }
    }
    dp = cur;
  }

  int ans = 0;

  for (int i = sum; i < dp.size(); i++) {
    if (dp[i]) {
      ans = i - sum;
      break;
    }
  }

  cout << ans;
}