#include <vector>
#include <unordered_set>
using namespace std;

std::vector<int> intersection(std::vector<int> a, std::vector<int> b) {
  vector<int> result;
  unordered_set<int> items (a.begin(), a.end());
  for (auto item : b) {
    if (items.count(item)) {
      result.push_back(item);
    }
  }
  return result;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}