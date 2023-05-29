// https://leetcode.com/problems/design-parking-system/

#include <vector>
using namespace std;

// time: O(1)
// space: O(1)

class ParkingSystem {
public:
    vector<int> count, cap;

    ParkingSystem(int big, int medium, int small) {
        count.resize(3);
        cap = { big, medium, small };
    }
    
    bool addCar(int carType) {
        int i = carType - 1;
        if (count[i] == cap[i])
            return false;
        count[i]++;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */