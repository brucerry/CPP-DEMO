#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

int main() {
  int n;
  string cmd;
  stack<set<string>> stack;

  cin >> n;

  while (n--) {
    cin >> cmd;

    if (cmd == "PUSH") {
      stack.push({});
    }

    else if (cmd == "DUP") {
      stack.push(stack.top());
    }

    else if (cmd == "UNION") {
      set<string> first = stack.top();
      stack.pop();
      set<string> second = stack.top();
      if (first != second) {
        stack.pop();
        set<string> setUnion;
        set_union(first.begin(), first.end(), second.begin(), second.end(), inserter(setUnion, setUnion.begin()));
        stack.push(setUnion);
      }
    }

    else if (cmd == "INTERSECT") {
      set<string> first = stack.top();
      stack.pop();
      set<string> second = stack.top();
      if (first != second) {
        stack.pop();
        set<string> setIntersection;
        set_intersection(first.begin(), first.end(), second.begin(), second.end(), inserter(setIntersection, setIntersection.begin()));
        stack.push(setIntersection);
      }
    }

    else {
      set<string> first = stack.top();
      stack.pop();
      set<string> second = stack.top();
      stack.pop();
      string firstSubsets;
      for (const string& subset : first) {
        firstSubsets += subset;
      }
      second.insert("{" + firstSubsets + "}");
      stack.push(second);
    }

    cout << stack.top().size() << endl;
  }
}