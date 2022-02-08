#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



/*
  using max heap

  time: O(n + k * log(n))
  space: O(1)
*/
int findKthLargestElement(vector<int> numbers, int k) {
  make_heap(numbers.begin(), numbers.end());

  int value;
  while (k--) {
    pop_heap(numbers.begin(), numbers.end());
    value = numbers.back();
    numbers.pop_back();
  }

  return value;
}





// time: O(n * log(n))
// space: O(1)
// int findKthLargestElement(vector<int> numbers, int k) {
//   sort(numbers.begin(), numbers.end());
//   return numbers[numbers.size() - k];
// }


int main() {
  cout << findKthLargestElement({4, 2, 9, 7, 5, 6, 7, 1, 3}, 4); // 6
}