#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
  int n;
  string cmd;
  map<set<int>, int> myMap;
  stack<set<int>> myStack;
  static int id = 0;

  cin >> n;

  while (n--) {
    cin >> cmd;

    if (cmd == "PUSH") {
      myStack.push({});
      if (myMap.count(myStack.top()) == 0) {
        myMap[myStack.top()] = id++;
      }
    }

    else if (cmd == "DUP") {
      myStack.push(myStack.top());
    }

    else if (cmd == "UNION") {
      set<int> first = myStack.top();
      myStack.pop();
      set<int> second = myStack.top();
      if (first != second) {
        myStack.pop();
        set<int> setUnion;
        set_union(first.begin(), first.end(), second.begin(), second.end(), inserter(setUnion, setUnion.begin()));
        myStack.push(setUnion);
        if (myMap.count(myStack.top()) == 0) {
          myMap[myStack.top()] = id++;
        }
      }
    }

    else if (cmd == "INTERSECT") {
      set<int> first = myStack.top();
      myStack.pop();
      set<int> second = myStack.top();
      if (first != second) {
        myStack.pop();
        set<int> setIntersect;
        set_intersection(first.begin(), first.end(), second.begin(), second.end(), inserter(setIntersect, setIntersect.begin()));
        myStack.push(setIntersect);
        if (myMap.count(myStack.top()) == 0) {
          myMap[myStack.top()] = id++;
        }
      }
    }

    else {
      set<int> first = myStack.top();
      myStack.pop();
      set<int> second = myStack.top();
      if (second.count(myMap[first]) == 0) {
        myStack.pop();
        second.insert(myMap[first]);
        myStack.push(second);
        if (myMap.count(myStack.top()) == 0) {
          myMap[myStack.top()] = id++;
        }
      }
    }

    cout << myStack.top().size() << endl;
  }
}