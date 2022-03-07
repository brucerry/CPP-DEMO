#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> nums;
  int n;

  cin >> n;

  nums.reserve(n);

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums.emplace_back(num);
  }
  

}