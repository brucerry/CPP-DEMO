#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> separateSubset(string& str) {
  vector<string> result;
  int count = 0;
  string subset;

  for (int i = 1; i < str.length() - 1; i++) {
    subset += str[i];
    if (str[i] == '{') {
      count++;
    } else {
      count--;
    }
    if (count == 0) {
      result.push_back(subset);
      subset.clear();
    }
  }

  return result;
}

string concatSubset(vector<string>& vec) {
  string result = "{";

  for (string& subset : vec) {
    result += subset;
  }

  return result + "}";
}

int main() {
  int n;
  string cmd;
  stack<string> stack;

  cin >> n;

  while (n--) {
    cin >> cmd;

    if (cmd == "PUSH") {
      stack.push("{}");
    }

    else if (cmd == "DUP") {
      stack.push(stack.top());
    }

    else if (cmd == "UNION") {
      vector<string> first = separateSubset(stack.top());
      stack.pop();
      vector<string> second = separateSubset(stack.top());
      stack.pop();
      unordered_set<string> firstSet (first.begin(), first.end());
      for (string& sec : second) {
        if (firstSet.count(sec) == 0) {
          first.push_back(sec);
        }
      }
      stack.push(concatSubset(first));
    }

    else if (cmd == "INTERSECT") {
      vector<string> first = separateSubset(stack.top());
      stack.pop();
      vector<string> second = separateSubset(stack.top());
      stack.pop();
      unordered_set<string> firstSet (first.begin(), first.end());
      vector<string> intersect;
      for (string& sec : second) {
        if (firstSet.count(sec)) {
          intersect.push_back(sec);
        }
      }
      stack.push(concatSubset(intersect));
    }

    else {
      string first = stack.top();
      stack.pop();
      string second = stack.top();
      stack.pop();
      vector<string> secondVec = separateSubset(second);
      unordered_set<string> secondSet (secondVec.begin(), secondVec.end());
      if (secondSet.count(first) == 0) {
        second.insert(second.length() - 1, first);
      }
      stack.push(second);
    }

    // cout << stack.top() << endl;
    cout << separateSubset(stack.top()).size() << endl;
  }
}