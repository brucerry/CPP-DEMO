// https://leetcode.com/problems/design-a-text-editor/

#include <string>
using namespace std;

// time: O(k)
// space: O(n)

class TextEditor {
public:
  TextEditor() {
    
  }
  
  void addText(string text) {
    left += text;
  }
  
  int deleteText(int k) {
    int count = 0;
    while (k-- and left.size()) {
      left.pop_back();
      count++;
    }
    return count;
  }
  
  string cursorLeft(int k) {
    while (k-- and left.size()) {
      char c = left.back();
      left.pop_back();
      right += c;
    }
    int n = left.size();
    return left.substr(max(0, n - 10));
  }
  
  string cursorRight(int k) {
    while (k-- and right.size()) {
      char c = right.back();
      right.pop_back();
      left += c;
    }
    int n = left.size();
    return left.substr(max(0, n - 10));
  }

private:
  string left, right;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */