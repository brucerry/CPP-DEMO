// https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
    int hrs = 0;
    int curExp = initialExperience, curEnergy = initialEnergy;
    
    for (int i = 0; i < energy.size(); i++) {
      if (curExp <= experience[i]) {
        hrs += experience[i] - curExp + 1;
        curExp = experience[i] + 1;
      }
      
      if (curEnergy <= energy[i]) {
        hrs += energy[i] - curEnergy + 1;
        curEnergy = energy[i] + 1;
      }
      
      curExp += experience[i];
      curEnergy -= energy[i];
    }
    
    return hrs;
  }
};