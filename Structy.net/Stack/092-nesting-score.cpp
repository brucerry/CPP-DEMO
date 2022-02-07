#include <string>
#include <vector>
using namespace std;

int nestingScore(std::string str) {
  vector<int> vector {0};
  
  for (auto ch : str) {
    if (ch == '[') {
      vector.push_back(0);
    } else {
      int current = vector.back();
      vector.pop_back();
      if (current == 0) {
        vector.back()++;
      } else {
        vector.back() += current * 2;
      }
    }
  }
  
  return vector.front();
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}