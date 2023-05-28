// https://leetcode.com/problems/buy-two-chocolates/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = 101, min2 = 101;
        for (int price : prices) {
            if (price < min1) {
                min2 = min1;
                min1 = price;
            }
            else if (price < min2) {
                min2 = price;
            }
        }
        int cost = min1 + min2;
        return cost > money ? money : money - cost;
    }
};