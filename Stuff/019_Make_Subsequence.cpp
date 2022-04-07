#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  int T;

  cin >> T;

  while (T--) {
    string s, t;

    cin >> s >> t;
    
    unordered_map<char, int> map; // char, firstIndex

    for (int i = 0; i < s.length(); i++) {
      if (map.count(s[i]) == 0) {
        map[s[i]] = i;
      }
    }

    int ans = 1, sCurIndex = -1;

    for (int i = 0; i < t.length(); i++) {
      if (map.count(t[i]) == 0) {
        ans = -1;
        break;
      }
      size_t pos = s.find(t[i], sCurIndex + 1);
      if (pos == string::npos) {
        ans++;
        sCurIndex = map[t[i]];
      }
      else {
        sCurIndex = pos;
      }
    }

    cout << ans << endl;
  }
}