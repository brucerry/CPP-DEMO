#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;

int main() {
  map<int, pair<int, int>> content; // a -> (b, time)
  map<int, int> time; // time -> a
  int n, m;
  static int s_time = 0;

  cin >> n >> m;

  while (m--) {
    string cmd;
    int a, b;

    cin >> cmd >> a;
    if (cmd == "set") {
      cin >> b;
    }

    if (cmd == "set") {
      if (content.count(a)) {
        int originalTime = content[a].second;
        time.erase(originalTime);
      }
      else if (content.size() == n) {
        int earliestChapter = time.begin()->second;
        content.erase(earliestChapter);
        time.erase(time.begin());
      }
      content[a] = {b, s_time};
      time[s_time] = a;
      s_time++;
    }

    else {
      if (content.count(a)) {
        int originalContent = content[a].first;
        int originalTime = content[a].second;
        time.erase(originalTime);
        time[s_time] = a;
        content[a] = {originalContent, s_time};
        s_time++;
        cout << originalContent << endl;
      }
      else {
        cout << -1 << endl;
      }
    }
  }
}