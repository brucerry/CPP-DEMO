#include <iostream>
#include <string>
#include <stack>
#include <set>
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

  set<string> subset (vec.begin(), vec.end());
  for (const string& str : subset) {
    result += str;
  }

  return result + "}";
}

int main() {
  int n;
  string cmd;
  stack<string> stack;
  // stack.push("{{}{{{}}}}");
  // stack.push("{{}{{}}}");

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
      string first = stack.top();
      stack.pop();
      string second = stack.top();
      stack.pop();
      vector<string> firstVec = separateSubset(first);
      vector<string> secondVec = separateSubset(second);
      firstVec.insert(firstVec.end(), secondVec.begin(), secondVec.end());
      stack.push(concatSubset(firstVec));
    }

    else if (cmd == "INTERSECT") {
      string first = stack.top();
      stack.pop();
      string second = stack.top();
      stack.pop();
      vector<string> firstVec = separateSubset(first);
      vector<string> secondVec = separateSubset(second);
      set<string> firstSet (firstVec.begin(), firstVec.end());
      vector<string> intersect;
      for (string& sec : secondVec) {
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
      secondVec.push_back(first);
      stack.push(concatSubset(secondVec));
    }

    // cout << "stack top is: " << stack.top() << endl;
    // cout << "stack remains: " << stack.size() << endl;

    cout << separateSubset(stack.top()).size() << endl;
  }
}