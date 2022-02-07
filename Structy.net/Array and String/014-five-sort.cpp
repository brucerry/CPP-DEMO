#include <vector>
#include <iostream>
using namespace std;

std::vector<int>& fiveSort(std::vector<int> &numbers) {
  int i = 0, j = numbers.size() - 1;
  while (true) {
    while (numbers[i] != 5) i++;
    while (numbers[j] == 5) j--;
    if (i < j) swap(numbers[i], numbers[j]);
    else break;
  }
  return numbers;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}