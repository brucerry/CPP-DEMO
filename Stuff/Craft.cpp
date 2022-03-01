#include <iostream>
#include <string>
#include <vector>
using namespace std;

// put the blocks stacked on the target block (slots[slot][index]) back to the top of their original slots
void distribute(vector<vector<int>>& slots, vector<pair<int, int>>& location, int slot, int index) {
  for (int i = slots[slot].size() - 1; i >= index + 1 ; i--) {
    int block = slots[slot][i];
    slots[slot].pop_back();
    slots[block].push_back(block);
    location[block] = {block, slots[block].size() - 1};
  }
}

int main() {
  int n, m;
  int blockA, blockB;
  string cmd1, cmd2;

  cin >> n >> m;

  // init
  vector<vector<int>> slots (n);
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
    
    auto& [ slotA, indexA ] = location[blockA];
    auto& [ slotB, indexB ] = location[blockB];

    if (slotA == slotB) continue;

    if (cmd1 == "move") {
      if (cmd2 == "onto") {
        distribute(slots, location, slotA, indexA);
        distribute(slots, location, slotB, indexB);
        slots[slotA].pop_back();
        slots[slotB].push_back(blockA);
        location[blockA] = {slotB, indexB + 1};
      }

      else {
        distribute(slots, location, slotA, indexA);
        slots[slotA].pop_back();
        slots[slotB].push_back(blockA);
        location[blockA] = {slotB, slots[slotB].size() - 1};
      }
    }

    else {
      if (cmd2 == "onto") {
        distribute(slots, location, slotB, indexB);
        slots[slotB].insert(slots[slotB].end(), slots[slotA].begin() + indexA, slots[slotA].end());
        slots[slotA].erase(slots[slotA].begin() + indexA, slots[slotA].end());
        for (int i = indexB + 1; i < slots[slotB].size(); i++) {
          location[slots[slotB][i]] = {slotB, i};
        }
      }

      else {
        int slotBsize = slots[slotB].size();
        slots[slotB].insert(slots[slotB].end(), slots[slotA].begin() + indexA, slots[slotA].end());
        slots[slotA].erase(slots[slotA].begin() + indexA, slots[slotA].end());
        for (int i = slotBsize; i < slots[slotB].size(); i++) {
          location[slots[slotB][i]] = {slotB, i};
        }
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