#include <vector>
using namespace std;



// time: O(log(n))
// space: O(1)
int binarySearch(std::vector<int> numbers, int target) {
  int head = 0;
  int tail = numbers.size() - 1;
  while (head <= tail) {
    int mid = (head + tail) / 2;
    if (numbers[mid] > target) tail = mid - 1;
    else if (numbers[mid] < target) head = mid + 1;
    else return mid;
  }
  return -1;
}



// time: O(log(n))
// space: O(n)
int _binarySearch(vector<int> numbers, int target, int head, int tail) {
  if (head <= tail) {
    int mid = (head + tail) / 2;
    if (numbers[mid] > target) return _binarySearch(numbers, target, head, mid - 1);
    else if (numbers[mid] < target) return _binarySearch(numbers, target, mid + 1, tail);
    else return mid;
  }
  return -1;
}

int _binarySearch(std::vector<int> numbers, int target) {
  return _binarySearch(numbers, target, 0, numbers.size() - 1);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}