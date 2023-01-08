// https://leetcode.com/problems/categorize-box-according-to-criteria/

#include <string>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long volume = (long)length * width * height;
        bool bulky = length >= 1e4 or width >= 1e4 or height >= 1e4 or mass >= 1e4 or volume >= 1e9;
        bool heavy = mass >= 100;
        if (bulky and heavy)
            return "Both";
        if (bulky)
            return "Bulky";
        if (heavy)
            return "Heavy";
        return "Neither";
    }
};