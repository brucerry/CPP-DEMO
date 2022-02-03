#include <vector>
#include <string>
using namespace std;


std::vector<std::vector<std::string>> permutations(std::vector<std::string> elements) {
  if (elements.size() == 0) return {{}};
  
  vector<vector<string>> result;
  for (auto el : permutations(vector<string>(elements.begin() + 1, elements.end()))) {
    for (int i = 0; i <= el.size(); i++) {
      vector<string> elCopy (el);
      elCopy.insert(elCopy.begin() + i, elements[0]);
      result.push_back(elCopy);
    }
  }
  
  return result;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}