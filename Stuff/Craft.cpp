#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, m;
  int blockA, blockB;
  string cmd1, cmd2;

  cin >> n >> m;

  vector<vector<int>> slots (n, vector<int>());
  vector<pair<int, int>> location (n);

  for (int i = 0; i < n; i++) {
    slots[i].push_back(i);
    location[i] = {i, 0};
  }




  // cases
  while (m--) {
    cin >> cmd1 >> blockA >> cmd2 >> blockB;

    blockA--;
    blockB--;
    
    auto [ slotA, indexA ] = location[blockA];
    auto [ slotB, indexB ] = location[blockB];

    if (slotA == slotB) {
      cout << "same slot" << endl;
      continue;
    }

    if (cmd1 == "move") {
      if (cmd2 == "onto") {
        for (int i = slots[slotA].size() - 1; i >= indexA + 1; i--) {
          int block = slots[slotA][i];
          slots[slotA].pop_back();
          slots[block].push_back(block);
          location[block] = {block, slots[block].size() - 1};
        }
        for (int i = slots[slotB].size() - 1; i >= indexB + 1; i--) {
          int block = slots[slotB][i];
          slots[slotB].pop_back();
          slots[block].push_back(block);
          location[block] = {block, slots[block].size() - 1};
        }
        slots[slotA].pop_back();
        slots[slotB].push_back(blockA);
        location[blockA] = {slotB, slots[slotB].size() - 1};
      }

      else {

      }
    }

    else {
      if (cmd2 == "onto") {

      }

      else {

      }
    }
  }






  // output
  for (int i = 0; i < n; i++) {
    cout << i + 1 << ":";
    for (int j = 0; j < slots[i].size(); j++) {
      cout << " " << slots[i][j] + 1;
    }
    cout << endl;
  }
}