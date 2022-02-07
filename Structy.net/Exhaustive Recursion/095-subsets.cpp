#include <vector>
#include <string>
using namespace std;

std::vector<std::vector<std::string>> subsets(std::vector<std::string> elements) {
  if (elements.size() == 0) return {{}};
  
  vector<vector<string>> ntake = subsets(vector<string>(elements.begin() + 1, elements.end()));
  
  vector<vector<string>> result;
  for (auto el : ntake) {
    result.push_back(el);
    el.push_back(elements[0]);
    result.push_back(el);
  }
  
  return result;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}