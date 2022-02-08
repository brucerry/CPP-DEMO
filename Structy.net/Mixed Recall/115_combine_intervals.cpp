#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;


std::vector<std::tuple<int, int>> combineIntervals(std::vector<std::tuple<int, int>> intervals) {
  vector<tuple<int, int>> combined;
  sort(intervals.begin(), intervals.end());
  combined.push_back(intervals[0]);
  
  for (int i = 1; i < intervals.size(); i++) {
    auto [ currentLow, currentHigh ] = intervals[i];
    auto [ lastLow, lastHigh ] = combined.back();
    if (currentLow > lastHigh) combined.push_back({currentLow, currentHigh});
    else combined.back() = {lastLow, max(currentHigh, lastHigh)};
  }
  
  return combined;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}