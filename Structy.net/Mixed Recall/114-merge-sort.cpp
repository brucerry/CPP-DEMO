#include <vector>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
  vector<int> result;
  
  int l = 0, r = 0;
  while (l < left.size() && r < right.size()) {
    if (left[l] < right[r]) {
      result.push_back(left[l++]);
    } else {
      result.push_back(right[r++]);
    }
  }
  
  while (l < left.size()) result.push_back(left[l++]);
  while (r < right.size()) result.push_back(right[r++]);
  
  return result;
}

std::vector<int> mergeSort(std::vector<int> numbers) {
  if (numbers.size() == 1) return {numbers[0]};
  
  int mid = numbers.size() / 2;
  vector<int> left (numbers.begin(), numbers.begin() + mid);
  vector<int> right (numbers.begin() + mid, numbers.end());
  vector<int> sortedLeft = mergeSort(left);
  vector<int> sortedRight = mergeSort(right);
  return merge(sortedLeft, sortedRight);
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}