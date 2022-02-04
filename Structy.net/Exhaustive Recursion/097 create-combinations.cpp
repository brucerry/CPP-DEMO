#include <vector>
#include <string>
using namespace std;

std::vector<std::vector<std::string>> createCombinations(std::vector<std::string> items, int size) {
  if (size == 0) return {{}};
  if (size > items.size()) return {};
  
  string dropItem = items.front();
  vector<string> remain = vector<string>(items.begin() + 1, items.end());
  
  vector<vector<string>> result;
  for (auto comb : createCombinations(remain, size - 1)) {
    comb.push_back(dropItem);
    result.push_back(comb);
  }
  for (auto comb : createCombinations(remain, size)) {
    result.push_back(comb);
  }
  
  return result;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}