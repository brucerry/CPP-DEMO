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
  map<int, set<int>> id2set;
  stack<int> myStack;
  static int id = 1;

  cin >> n;

  while (n--) {
    cin >> cmd;

    if (cmd == "PUSH") {
      myStack.push(0);
      if (id2set.count(0) == 0) {
        id2set[0] = {};
      }
      if (myMap.count({}) == 0) {
        myMap[{}] = 0;
      }
    }

    else if (cmd == "DUP") {
      myStack.push(myStack.top());
    }

    else if (cmd == "UNION") {
      int first = myStack.top();
      myStack.pop();
      int second = myStack.top();
      if (first != second) {
        myStack.pop();
        set<int> firstSet = id2set[first];
        set<int> secondSet = id2set[second];
        set<int> setUnion;
        set_union(firstSet.begin(), firstSet.end(), secondSet.begin(), secondSet.end(), inserter(setUnion, setUnion.begin()));
        if (myMap.count(setUnion) == 0) {
          myMap[setUnion] = id;
          id2set[id] = setUnion;
          myStack.push(id);
          id++;
        }
        else {
          myStack.push(myMap[setUnion]);
        }
      }
    }

    else if (cmd == "INTERSECT") {
      int first = myStack.top();
      myStack.pop();
      int second = myStack.top();
      if (first != second) {
        myStack.pop();
        set<int> firstSet = id2set[first];
        set<int> secondSet = id2set[second];
        set<int> setIntersect;
        set_intersection(firstSet.begin(), firstSet.end(), secondSet.begin(), secondSet.end(), inserter(setIntersect, setIntersect.begin()));
        if (myMap.count(setIntersect) == 0) {
          myMap[setIntersect] = id;
          id2set[id] = setIntersect;
          myStack.push(id);
          id++;
        }
        else {
          myStack.push(myMap[setIntersect]);
        }
      }
    }

    else {
      int first = myStack.top();
      myStack.pop();
      int second = myStack.top();
      set<int> secondSet = id2set[second];
      if (secondSet.count(first) == 0) {
        myStack.pop();
        secondSet.insert(first);
        if (myMap.count(secondSet) == 0) {
          myMap[secondSet] = id;
          id2set[id] = secondSet;
          myStack.push(id);
          id++;
        }
        else {
          myStack.push(myMap[secondSet]);
        }
      }
    }

    cout << id2set[myStack.top()].size() << endl;
  }
}